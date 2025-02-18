/*++
Copyright (c) 2017 Microsoft Corporation

Module Name:

    <name>

Abstract:

    <abstract>

Author:

    Lev Nachmanson (levnach)

Revision History:


--*/
// clang-format off
#include "math/lp/lp_settings.h"
#include "math/lp/matrix_def.h"
#include "math/lp/static_matrix.h"
#include <string>
#ifdef Z3DEBUG
template bool lp::matrix<lp::mpq, lp::numeric_pair<lp::mpq> >::is_equal(lp::matrix<lp::mpq, lp::numeric_pair<lp::mpq> > const&);
template bool lp::matrix<lp::mpq, lp::mpq>::is_equal(lp::matrix<lp::mpq, lp::mpq> const&);
#endif
template void lp::print_matrix<lp::mpq, lp::numeric_pair<lp::mpq> >(lp::matrix<lp::mpq, lp::numeric_pair<lp::mpq> > const *, std::basic_ostream<char, std::char_traits<char> > &);
template void lp::print_matrix<lp::mpq, lp::mpq>(lp::matrix<lp::mpq, lp::mpq> const*, std::ostream&);
