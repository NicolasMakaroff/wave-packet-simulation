// This file is part of a time-dependent non-relatistic Schrödinger equation solver, 
// a tiny C++ solver.
//
// Copyright (C) 2020 Nicolas Makaroff <nicolas.makaroff@ensiie.fr>
// 
// This Source Code Form is subject to the terms of the MiT
// Public License. If a copy of the MPL was not distributed
// with this file, You can obtain one at https://opensource.org/licenses/MIT.


#include "solver.hpp"

unsigned int solver::Factorial(unsigned int n){
        return n <= 1 ? n : Factorial(n-1)*n;
}


