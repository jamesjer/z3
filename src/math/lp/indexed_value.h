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
#pragma once

namespace lp {
template <typename T>
class indexed_value {
public:
    T m_value;
    // the idea is that m_index for a row element gives its column, and for a column element its row
    unsigned m_index;
    // m_other is the offset of the corresponding element in its vector : for a row element it points to the column element offset,
    // for a column element it points to the row element offset
    unsigned m_other;
    indexed_value() {}

    indexed_value(T v, unsigned i, unsigned other) :
        m_value(v), m_index(i), m_other(other) {
    }

    const T & value() const {
        return m_value;
    }

    void set_value(T val) {
        m_value = val;
    }
};
}
