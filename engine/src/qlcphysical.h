/*
  Q Light Controller Plus
  qlcphysical.h

  Copyright (C) Heikki Junnila
                Massimo Callegari

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#ifndef QLCPHYSICAL_H
#define QLCPHYSICAL_H

#include <QString>
#include <QSize>

class QXmlStreamReader;
class QXmlStreamWriter;

/** @addtogroup engine Engine
 * @{
 */

#define KXMLQLCPhysical QStringLiteral("Physical")

#define KXMLQLCPhysicalBulb         QStringLiteral("Bulb")
#define KXMLQLCPhysicalBulbType     QStringLiteral("Type")
#define KXMLQLCPhysicalBulbLumens   QStringLiteral("Lumens")
#define KXMLQLCPhysicalBulbColourTemperature QStringLiteral("ColourTemperature")

#define KXMLQLCPhysicalLens             QStringLiteral("Lens")
#define KXMLQLCPhysicalLensName         QStringLiteral("Name")
#define KXMLQLCPhysicalLensDegreesMin   QStringLiteral("DegreesMin")
#define KXMLQLCPhysicalLensDegreesMax   QStringLiteral("DegreesMax")

#define KXMLQLCPhysicalDimensions       QStringLiteral("Dimensions")
#define KXMLQLCPhysicalDimensionsWeight QStringLiteral("Weight")
#define KXMLQLCPhysicalDimensionsWidth  QStringLiteral("Width")
#define KXMLQLCPhysicalDimensionsHeight QStringLiteral("Height")
#define KXMLQLCPhysicalDimensionsDepth  QStringLiteral("Depth")

#define KXMLQLCPhysicalLayout QStringLiteral("Layout")

#define KXMLQLCPhysicalFocus        QStringLiteral("Focus")
#define KXMLQLCPhysicalFocusType    QStringLiteral("Type")
#define KXMLQLCPhysicalFocusPanMax  QStringLiteral("PanMax")
#define KXMLQLCPhysicalFocusTiltMax QStringLiteral("TiltMax")

#define KXMLQLCPhysicalTechnical                    QStringLiteral("Technical")
#define KXMLQLCPhysicalTechnicalPowerConsumption    QStringLiteral("PowerConsumption")
#define KXMLQLCPhysicalTechnicalDmxConnector        QStringLiteral("DmxConnector")


/**
 * QLCPhysical represents the physical properties of a fixture (in a certain
 * mode). These properties include weight, dimensions, light source, lens,
 * movement capabilities and beam width.
 */
class QLCPhysical
{
    /************************************************************************
     * Initialization
     ************************************************************************/
public:
    QLCPhysical();
    QLCPhysical(const QLCPhysical &other);

    virtual ~QLCPhysical();

    QLCPhysical& operator=(const QLCPhysical& physical);

    bool isEmpty() const;

    /************************************************************************
     * Properties
     ************************************************************************/
public:
    void setBulbType(const QString& type);
    QString bulbType() const;

    void setBulbLumens(int lumens);
    int bulbLumens() const;

    void setBulbColourTemperature(int temp);
    int bulbColourTemperature() const;

    void setWeight(double weight);
    double weight() const;

    void setWidth(int width);
    int width() const;

    void setHeight(int height);
    int height() const;

    void setDepth(int depth);
    int depth() const;

    void setLensName(const QString& name);
    QString lensName() const;

    void setLensDegreesMin(double degrees);
    double lensDegreesMin() const;

    void setLensDegreesMax(double degrees);
    double lensDegreesMax() const;

    void setFocusType(const QString& type);
    QString focusType() const;

    void setFocusPanMax(int pan);
    int focusPanMax() const;

    void setFocusTiltMax(int tilt);
    int focusTiltMax() const;

    void setLayoutSize(QSize size);
    QSize layoutSize() const;

    void setPowerConsumption(int watt);
    int powerConsumption() const;

    void setDmxConnector(const QString& type);
    QString dmxConnector() const;

protected:
    QString m_bulbType;
    int m_bulbLumens;
    int m_bulbColourTemperature;

    double m_weight;
    int m_width;
    int m_height;
    int m_depth;

    QString m_lensName;
    double m_lensDegreesMin;
    double m_lensDegreesMax;

    QString m_focusType;
    int m_focusPanMax;
    int m_focusTiltMax;
    QSize m_layout;

    int m_powerConsumption;
    QString m_dmxConnector;

    /************************************************************************
     * Load & Save
     ************************************************************************/
public:
    /** Load physical values from the given QXmlStreamReader */
    bool loadXML(QXmlStreamReader &doc);

    /** Save physical values to the given XML tag in the given document */
    bool saveXML(QXmlStreamWriter *doc);
};

/** @} */

#endif
