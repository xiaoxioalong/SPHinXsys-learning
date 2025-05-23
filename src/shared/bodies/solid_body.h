/* ------------------------------------------------------------------------- *
 *                                SPHinXsys                                  *
 * ------------------------------------------------------------------------- *
 * SPHinXsys (pronunciation: s'finksis) is an acronym from Smoothed Particle *
 * Hydrodynamics for industrial compleX systems. It provides C++ APIs for    *
 * physical accurate simulation and aims to model coupled industrial dynamic *
 * systems including fluid, solid, multi-body dynamics and beyond with SPH   *
 * (smoothed particle hydrodynamics), a meshless computational method using  *
 * particle discretization.                                                  *
 *                                                                           *
 * SPHinXsys is partially funded by German Research Foundation               *
 * (Deutsche Forschungsgemeinschaft) DFG HU1527/6-1, HU1527/10-1,            *
 *  HU1527/12-1 and HU1527/12-4.                                             *
 *                                                                           *
 * Portions copyright (c) 2017-2023 Technical University of Munich and       *
 * the authors' affiliations.                                                *
 *                                                                           *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may   *
 * not use this file except in compliance with the License. You may obtain a *
 * copy of the License at http://www.apache.org/licenses/LICENSE-2.0.        *
 *                                                                           *
 * ------------------------------------------------------------------------- */
/**
 * @file    solid_body.h
 * @brief 	This is the class for bodies used for solid BCs or Elastic structure.
 * @author	Chi Zhang and Xiangyu Hu
 */

#ifndef SOLID_BODY_H
#define SOLID_BODY_H

#include "base_body.h"
#include "base_body_part.h"

namespace SPH
{
/**
 * @brief pre-claimed class.
 */
class SPHSystem;
class BaseParticles;
/**
 * @class SolidBody
 * @brief Declaration of solid body which is used for Solid BCs and derived from RealBody.
 */
class SolidBody : public RealBody
{
    void addSolidBodyToSPHSystem();

  public:
    template <typename... Args>
    SolidBody(Args &&...args)
        : RealBody(std::forward<Args>(args)...)
    {
        addSolidBodyToSPHSystem();
        defineAdaptation<SPHAdaptation>(1.15);
    };
    virtual ~SolidBody() {};
};
} // namespace SPH
#endif // SOLID_BODY_H
