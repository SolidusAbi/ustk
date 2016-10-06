/****************************************************************************
 *
 * This file is part of the UsTk software.
 * Copyright (C) 2014 by Inria. All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License ("GPL") as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * See the file COPYING at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * This software was developed at:
 * INRIA Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 * http://www.irisa.fr/lagadic
 *
 * If you have questions regarding the use of this file, please contact the
 * authors at Alexandre.Krupa@inria.fr
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * Authors:
 * Pierre Chatelain
 * Marc Pouliquen
 *
 *****************************************************************************/

#include<visp3/ustk_core/usImagePostScanSettings.h>

 /**
 * Default constructor, all parameters set de default values.
 */
usImagePostScanSettings::usImagePostScanSettings() : usImageSettings(), m_widthResolution(0.0), m_heightResolution(0.0)
{

}

/**
* Full parameters constructor, all parameters settables.
*/
usImagePostScanSettings::usImagePostScanSettings(double probeRadius, double scanLinePitch, bool isConvex, double height_resolution, double width_resolution) : usImageSettings(probeRadius, scanLinePitch, isConvex), m_widthResolution(width_resolution), m_heightResolution(height_resolution)
{

}

/**
* Full parameters constructor, all parameters settables.
*/
usImagePostScanSettings::usImagePostScanSettings(usImageSettings basicSettings, double height_resolution, double width_resolution) : usImageSettings(basicSettings), m_widthResolution(width_resolution), m_heightResolution(height_resolution)
{

}

/**
* Destructor.
*/
usImagePostScanSettings::~usImagePostScanSettings() {}

/**
* Assignement operator.
* @param other usImagePostScanSettings to copy.
*/
usImagePostScanSettings& usImagePostScanSettings::operator=(const usImagePostScanSettings& other)
{
  usImageSettings::operator=(other);
  m_heightResolution = other.getHeightResolution();
  m_widthResolution = other.getWidthResolution();

  return *this;
}

/**
* Comparaison operator.
* @param other usImagePostScanSettings to test.
*/
bool usImagePostScanSettings::operator==(const usImagePostScanSettings& other)
{
  return(usImageSettings::operator==(other) &&
    m_widthResolution == other.getWidthResolution() &&
    m_heightResolution == other.getHeightResolution());
}

/**
* Operator to print image informations on a stream.
*/
VISP_EXPORT std::ostream& operator<<(std::ostream& out, const usImagePostScanSettings &other)
{
  out << static_cast<const usImageSettings &>(other);
  return out << "Height resolution : " << other.getHeightResolution() <<
    "Width resolution : " << other.getWidthResolution();
}

/**
* Width resolution setter.
* @param widthResolution Width resolution to set.
*/
void usImagePostScanSettings::setWidthResolution(const double widthResolution)
{
  m_widthResolution = widthResolution;
}

/**
* Width resolution getter.
*/
double usImagePostScanSettings::getWidthResolution() const
{
  return m_widthResolution;
}

/**
* Height resolution setter.
* @param heightResolution Height resolution to set.
*/
void usImagePostScanSettings::setHeightResolution(const double heightResolution)
{
  m_heightResolution = heightResolution;
}

/**
* Height resolution getter.
*/
double usImagePostScanSettings::getHeightResolution() const
{
  return m_heightResolution;
}
