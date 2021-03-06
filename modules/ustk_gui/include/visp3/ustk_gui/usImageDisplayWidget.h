/****************************************************************************
 *
 * This file is part of the ustk software.
 * Copyright (C) 2016 - 2017 by Inria. All rights reserved.
 *
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * ("GPL") version 2 as published by the Free Software Foundation.
 * See the file LICENSE.txt at the root directory of this source
 * distribution for additional information about the GNU GPL.
 *
 * For using ustk with software that can not be combined with the GNU
 * GPL, please contact Inria about acquiring a ViSP Professional
 * Edition License.
 *
 * This software was developed at:
 * Inria Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 *
 * If you have questions regarding the use of this file, please contact
 * Inria at ustk@inria.fr
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Authors:
 * Marc Pouliquen
 *
 *****************************************************************************/

/**
 * @file usImageDisplayWidget.h
 * @brief Qt widget class for 2D ultrasound image display.
 */

#ifndef __usImageDisplayWidget_h_
#define __usImageDisplayWidget_h_

// VISP includes
#include <visp3/ustk_core/usConfig.h>

#if (defined(USTK_HAVE_VTK_QT) || defined(USTK_HAVE_QT5))

#include <QImage>
#include <QLabel>
#include <QPixmap>
#include <QResizeEvent>
#include <visp3/ustk_core/usImagePostScan2D.h>
#include <visp3/ustk_core/usImagePreScan2D.h>
#include <visp3/ustk_core/usPreScanToPostScan2DConverter.h>

/**
 * @class usImageDisplayWidget
 * @brief Qt widget class for 2D ultrasound image display.
 * @ingroup module_ustk_gui
 */

class VISP_EXPORT usImageDisplayWidget : public QWidget
{
  Q_OBJECT
public:
  usImageDisplayWidget();
  ~usImageDisplayWidget();

  void useScanConversion(bool enable);

  void resizeEvent(QResizeEvent *event);

public slots:
  void updateFrame(const vpImage<unsigned char> img);
  void updateFrame(const usImagePreScan2D<unsigned char> img);
  void updateFrame(const usImagePostScan2D<unsigned char> img);

protected:
  QLabel *m_label;

  // data
  QImage m_QImage;
  QPixmap m_pixmap;

  // scan conversion
  bool m_useScanConversion;
  usPreScanToPostScan2DConverter m_scanConverter;
  usImagePostScan2D<unsigned char> m_postScan;
  vpImage<unsigned char> m_image;
};
#endif // QT
#endif // __usImageDisplayWidget_h_
