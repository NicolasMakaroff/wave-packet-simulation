// This file is part of a time-dependent non-relatistic Schrödinger equation solver, 
// a tiny C++ solver.
//
// Copyright (C) 2020 Nicolas Makaroff <nicolas.makaroff@ensiie.fr>
// 
// This Source Code Form is subject to the terms of the MiT
// Public License. If a copy of the MPL was not distributed
// with this file, You can obtain one at https://opensource.org/licenses/MIT.


#include "solver.hpp"

#define hbar_ arma::datum::h_bar
#define mass_ (104.3961e-16)
#define cxi_ arma::cx_double(0.0, 1.0)


solver::Solver::Solver(arma::cx_mat input, double dx, double dy, double dt, arma::cx_mat in_pot)
:_dx_(dx),_dy_(dy), _dt_(dt){
        int n_rows_ = input.n_rows;
        int n_cols_ = input.n_cols;
        _psi_ = arma::cx_mat(n_rows_ + 2, n_cols_ + 2, arma::fill::zeros);
        _psi_.submat(1,1,n_rows_,n_cols_) = input;

        _potentials_ = arma::cx_mat(n_rows_ + 2, n_cols_ + 2, arma::fill::zeros);
        _potentials_.submat(1,1,n_rows_,n_cols_);

        _constants_ = arma::cx_mat(_psi_.n_rows, _psi_.n_cols, arma::fill::zeros);
	for (arma::uword i = 0; i < _constants_.n_cols - 1; i++) {
		_constants_(i+1, i) = 1;
		_constants_(i, i+1) = 1;
	}
}

void solver::Solver::FTCS(){

        arma::cx_double cte_ = cxi_*hbar_*_dt_;
        arma::cx_mat _first_term_ = cte_*(1/(2*mass_*_dx_*_dx_))*_constants_*_psi_;
        arma::cx_mat _second_term_ = cte_*(1/(2*mass_*_dy_*_dy_))*_psi_*_constants_;
        arma::cx_mat _third_term_ = cte_*(_dt_/(cxi_*hbar_))*(_potentials_+(cxi_*hbar_/_dt_)+(hbar_*hbar_/(mass_*_dx_*_dx_))+(hbar_*hbar_/(mass_*_dy_*_dy_))) % _psi_ ;

        arma::cx_mat _right_term_ = _first_term_ + _second_term_ + _third_term_;
        int size_ = _right_term_.n_rows - 2 ;
        _psi_.submat(1,1,size_,size_) = _right_term_.submat(1,1,size_,size_);
}

void solver::Solver::BTCS(){

        arma::cx_mat _first_term_ = -1.0 * (hbar_*hbar_/(2*mass_*_dx_*_dx_))*_constants_*_psi_;
        arma::cx_mat _second_term_ = -1.0 * (hbar_*hbar_/(2*mass_*_dy_*_dy_))*_psi_*_constants_;
        arma::cx_mat _third_term_ = cxi_ * hbar_ / _dt_ * _psi_;

        arma::cx_mat _left_term_ = cxi_*hbar_ - _potentials_ - hbar_*hbar_/(mass_*_dx_*_dx_) - hbar_*hbar_/(mass_*_dy_*_dy_);

        arma::cx_mat _right_term_ = (_first_term_ + _second_term_ + _third_term_)/_left_term_;
        int size_ =  _right_term_.n_rows;
        _psi_.submat(1,1,size_,size_) = _right_term_.submat(1,1,size_,size_);
}

void solver::Solver::CTCS(){
        

}

unsigned int solver::Factorial(unsigned int n){
        return n <= 1 ? n : Factorial(n-1)*n;
}


