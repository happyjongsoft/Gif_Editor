
/*!
	\file

	\author Igor Mironchik (igor.mironchik at gmail dot com).

	Copyright (c) 2020 Igor Mironchik

	Permission is hereby granted, free of charge, to any person
	obtaining a copy of this software and associated documentation
	files (the "Software"), to deal in the Software without
	restriction, including without limitation the rights to use,
	copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following
	conditions:

	The above copyright notice and this permission notice shall be
	included in all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
	EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
	OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
	NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
	WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
	OTHER DEALINGS IN THE SOFTWARE.
*/

// Widgets include.
#include <Widgets/Meter>

// Qt include.
#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>


int main( int argc, char ** argv )
{
	QApplication app( argc, argv );

	QWidget w;

	auto * l = new QVBoxLayout( &w );

	auto * m = new Meter( &w );

	m->setMinValue( 0.0 );
	m->setMaxValue( 220.0 );
	m->setValue( 90.0 );
	m->setBackgroundColor( Qt::black );
	m->setNeedleColor( Qt::blue );
	m->setTextColor( Qt::white );
	m->setGridColor( Qt::white );
	m->setLabel( QStringLiteral( "speed" ) );
	m->setUnitsLabel( QStringLiteral( "km/h" ) );
	m->setRadius( 200 );
	m->setStartScaleAngle( 35 );
	m->setStopScaleAngle( 325 );
	m->setScaleStep( 2.0 );
	m->setScaleGridStep( 10.0 );
	m->setDrawValue( true );
	m->setDrawGridValues( true );
	m->setDrawValuePrecision( 0 );
	m->setScaleLabelPrecision( 0 );
	m->setThresholdRange( 0, 110.0, 0 );
	m->setThresholdRange( 110.0, 130.0, 1, Qt::yellow );
	m->setThresholdRange( 130.0, 220.1, 2, Qt::red );

	l->addWidget( m );

	auto * s = new QSlider( Qt::Horizontal, &w );
	s->setMinimum( 0 );
	s->setMaximum( 220 );
	s->setValue( 90 );

	l->addWidget( s );

	QObject::connect( s, &QSlider::valueChanged, m, &Meter::setValue );

	w.show();

	return QApplication::exec();
}
