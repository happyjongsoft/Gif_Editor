
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
	m->setMaxValue( 30.0 );
	m->setValue( 15.0 );
	m->setBackgroundColor( Qt::white );
	m->setNeedleColor( Qt::black );
	m->setTextColor( Qt::black );
	m->setGridColor( Qt::black );
	m->setUnitsLabel( QStringLiteral( "Kgf/cm^2" ) );
	m->setRadius( 200 );
	m->setStartScaleAngle( 115 );
	m->setStopScaleAngle( 245 );
	m->setScaleStep( 0.0 );
	m->setScaleGridStep( 8.0 );
	m->setDrawValue( false );
	m->setDrawGridValues( true );
	m->setDrawValuePrecision( 0 );
	m->setScaleLabelPrecision( 0 );
	m->setThresholdRange( 0, 8.0, 0, Qt::red );
	m->setThresholdRange( 8.0, 16.0, 1, Qt::green );
	m->setThresholdRange( 16.0, 30.1, 2, Qt::yellow );

	l->addWidget( m );

	auto * s = new QSlider( Qt::Horizontal, &w );
	s->setMinimum( 0 );
	s->setMaximum( 30 );
	s->setValue( 15 );

	l->addWidget( s );

	QObject::connect( s, &QSlider::valueChanged, m, &Meter::setValue );

	w.show();

	return QApplication::exec();
}
