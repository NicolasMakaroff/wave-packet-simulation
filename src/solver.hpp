// This file is part of a time-dependent non-relatistic Schrödinger equation solver, 
// a tiny C++ solver.
//
// Copyright (C) 2020 Nicolas Makaroff <nicolas.makaroff@ensiie.fr>
// 
// This Source Code Form is subject to the terms of the MiT
// Public License. If a copy of the MPL was not distributed
// with this file, You can obtain one at https://opensource.org/licenses/MIT.


#include<armadillo>

#if !defined(_SOLVER_HPP_)
#define _SOLVER_HPP_


/** \ingroup Solver
  *
  * \class Solver
  *
  * \brief Solver for a time-dependent non-relatistic Schrödinger equation using FTCS,
  * BTCS and CTCS scheme.
  *
  * \param container_ the type of the matrix of which we are computing the COD.
  * \param potentials_
  * \param shift_operator_
  *
  * This class performs a PDE resolution using one of the three scheme implemented :
  * FTCS, Forward-Time Central-Space & BCTS, Backward Time, Centered Space &
  * CTCS Center-Time Central-Space.
  * The formula are recall for each scheme :
  * 
  * \b FTCS scheme :
  *  
  * \f[
  * \frac{i\hbar}{dt}\Psi^{(t+dt)} = \frac{-\hbar^2}{2m.dx^2}(\Psi_{(x+dx)} + \Psi_{(x-dx)}) 
  * - \frac{\hbar^2}{2m.dy^2}(\Psi_{(y+dy)} + \Psi_{(y-dy)})
  * + (V(x,y)+\frac{i\hbar}{dt} + \frac{\hbar^2}{m.dx^2} + \frac{\hbar^2}{m.dy^2})\Psi
  * \f]
  * 
  * \b BCTS scheme :
  * 
  * \f[
  * (\frac{i\hbar}{dt} - V(x,y) - \frac{\hbar^2}{m.dx^2} - \frac{\hbar^2}{m.dy^2})\Psi^{(t+dt)}
  * = \frac{-\hbar^2}{2m.dx^2}(\Psi_{(x+dx)}^{(t+dt)} + \Psi_{(x-dx)}^{(t+dt)}) 
  * - \frac{\hbar^2}{2m.dy^2}(\Psi_{(y+dy)}^{(t+dt)} + \Psi_{(y-dy)}^{(t+dt)})
  * + \frac{i\hbar}{dt}\Psi
  * \f]
  * 
  * \b CTCS scheme :
  * 
  * \f[
  * (\frac{2i\hbar}{dt} - V(x,y) - \frac{\hbar^2}{m.dx^2} - \frac{\hbar^2}{m.dy^2})\Psi^{(t+dt)}
  * \frac{-\hbar^2}{2m.dx^2}(\Psi_{(x+dx)} + \Psi_{(x-dx)}) 
  * - \frac{\hbar^2}{2m.dy^2}(\Psi_{(y+dy)} + \Psi_{(y-dy)})
  * \frac{-\hbar^2}{2m.dx^2}(\Psi_{(x+dx)}^{(t+dt)} + \Psi_{(x-dx)}^{(t+dt)}) 
  * - \frac{\hbar^2}{2m.dy^2}(\Psi_{(y+dy)}^{(t+dt)} + \Psi_{(y-dy)}^{(t+dt)})
  * + (V(x,y)+\frac{2i\hbar}{dt} + \frac{\hbar^2}{m.dx^2} + \frac{\hbar^2}{m.dy^2})\Psi
  * \f]
  * 
  * 
  * \sa solver::Solver()
  */

namespace solver{
        
        class Solver{
                private:
                arma::cx_mat _psi_;
                arma::cx_mat _potentials_;
                arma::cx_mat _constants_;
		double _dx_;
                double _dy_;
                double _dt_;
                double _precision_;

                public:
                Solver();
                Solver(arma::cx_mat init_psi, arma::cx_mat init_potential, double dx, double dy, double dt, double precision);
                void FTCS(void);
                void BTCS(void);
                void CTCS(void);

        };
unsigned int Factorial( unsigned int number );
double MatrixNorm(arma::cx_mat A, arma::cx_mat B);

}

#endif // _SOLVER_HPP_
