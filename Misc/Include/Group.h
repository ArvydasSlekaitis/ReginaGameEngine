///////////////////////////////////////////////////////////
//  Group.h
//  Created on:      22-05-2009
//  Last modified:   22-05-2009
//  Original author: Arvydas Slekaitis (C)
///////////////////////////////////////////////////////////


#ifndef MISC_GROUP_H
#define MISC_GROUP_H


namespace Regina
{

template <class T1, class T2, class T3> 
struct group_3
{
  T1 first;
  T2 second;
  T3 third;

  group_3() : first(T1()), second(T2()), third(T3()) {}
  group_3(const T1& x, const T2& y, const T3& z) : first(x), second(y), third(z) {}
  template <class U, class V, class W> group_3 (const group_3<U,V,W> &p) : first(p.first), second(p.second), third(p.third) { }
};


template <class T1, class T2, class T3, class T4> 
struct group_4
{
  T1 first;
  T2 second;
  T3 third;
  T4 fourth;

  group_4() : first(T1()), second(T2()), third(T3()), fourth(T4()) {}
  group_4(const T1& x, const T2& y, const T3& z, const T4& w) : first(x), second(y), third(z), fourth(w) {}
  template <class U, class V, class W, class Q> group_4 (const group_4<U,V,W,Q> &p) : first(p.first), second(p.second), third(p.third), fourth(p.fourth) { }
};


}


#endif