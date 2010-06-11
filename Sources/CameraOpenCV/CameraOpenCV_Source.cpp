/*!
 * \file CameraOpenCV.cpp
 * \brief Class responsible for retrieving images from camera.
 * \author mstefanc
 * \date 2010-06-10
 */

#include <iostream>

#include "CameraOpenCV_Source.hpp"

namespace Sources {
namespace CameraOpenCV {

CameraOpenCV_Source::CameraOpenCV_Source() {
	cout << "CameraOpenCV_Source::CameraOpenCV_Source()\n";

	initialize();
}

CameraOpenCV_Source::~CameraOpenCV_Source() {
	finish();

	cout << "CameraOpenCV_Source::~CameraOpenCV_Source()\n";
}

void CameraOpenCV_Source::initialize() {
	cout << "CameraOpenCV_Source::initialize()\n";
	newImage = registerEvent("newImage");

	registerStream("out_img", &out_img);

	cap.open(0);
}


void CameraOpenCV_Source::finish() {
	cout << "CameraOpenCV_Source::finish()\n";
	cap.release();
}


int CameraOpenCV_Source::step() {

	cap >> frame;

	out_img.write(frame);

	//imshow( "video2", frame );

	newImage->raise();
	return 0;
}


}//: namespace CameraOpenCV
}//: namespace Sources