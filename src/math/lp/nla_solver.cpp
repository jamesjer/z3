/*++
  Copyright (c) 2017 Microsoft Corporation

  Author:
    Lev Nachmanson (levnach)
    Nikolaj Bjorner (nbjorner)
  --*/
// clang-format off
#include "math/lp/nla_solver.h"
#include <map>
#include "math/lp/monic.h"
#include "math/lp/lp_utils.h"
#include "math/lp/var_eqs.h"
#include "math/lp/factorization.h"
#include "math/lp/nla_solver.h"
#include "math/lp/nla_core.h"
#include "math/polynomial/algebraic_numbers.h"

namespace nla {

    nla_settings& solver::settings() { return m_core->m_nla_settings; }

    void solver::add_monic(lpvar v, unsigned sz, lpvar const* vs) {
        m_core->add_monic(v, sz, vs);
    }

    void solver::add_idivision(lpvar q, lpvar x, lpvar y) {
        m_core->add_idivision(q, x, y);
    }

    void solver::add_rdivision(lpvar q, lpvar x, lpvar y) {
        m_core->add_rdivision(q, x, y);
    }

    void solver::add_bounded_division(lpvar q, lpvar x, lpvar y) {
        m_core->add_bounded_division(q, x, y);
    }

    void solver::set_relevant(std::function<bool(lpvar)>& is_relevant) {
        m_core->set_relevant(is_relevant);
    }
    
    bool solver::is_monic_var(lpvar v) const {
        return m_core->is_monic_var(v);
    }
    
    bool solver::need_check() { return m_core->has_relevant_monomial(); }
    
    lbool solver::check(vector<lemma>& l) {
        return m_core->check(l);
    }
    
    void solver::push(){
        m_core->push();
    }
    
    void solver::pop(unsigned n) {
        m_core->pop(n);
    }
    
    solver::solver(lp::lar_solver& s, reslimit& limit): 
        m_core(alloc(core, s, limit)) {
    }
    
    bool solver::influences_nl_var(lpvar j) const {    
        return m_core->influences_nl_var(j);
    }
    
    solver::~solver() {
        dealloc(m_core);
    }
    
    std::ostream& solver::display(std::ostream& out) const {    
        m_core->print_monics(out);
        if (use_nra_model()) 
            m_core->m_nra.display(out);
        return out;
    }
    
    bool solver::use_nra_model() const { return m_core->use_nra_model(); }

    core& solver::get_core() { return *m_core; }

    nlsat::anum_manager& solver::am() { return m_core->m_nra.am(); }

    nlsat::anum const& solver::am_value(lp::var_index v) const {
        SASSERT(use_nra_model());
        return m_core->m_nra.value(v);
    }
    
    void solver::collect_statistics(::statistics & st) {
        m_core->collect_statistics(st);
    }

    // ensure r = x^y, add abstraction/refinement lemmas
    lbool solver::check_power(lpvar r, lpvar x, lpvar y, vector<lemma>& lemmas) {
        return m_core->check_power(r, x, y, lemmas);
    }

    void solver::check_bounded_divisions(vector<lemma>& lemmas) {
        m_core->check_bounded_divisions(lemmas);
    }

}
