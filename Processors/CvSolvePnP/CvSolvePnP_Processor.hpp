/*
 * CvSolvePnP_Processor.hpp
 *
 *  Created on: 18-10-2010
 *      Author: mateusz
 */

#ifndef CVSOLVEPNP_PROCESSOR_HPP_
#define CVSOLVEPNP_PROCESSOR_HPP_

#include <cv.h>

#include "Component.hpp"
#include "Props.hpp"
#include "EventHandler.hpp"
#include "DataStream.hpp"

namespace Processors {

namespace CvSolvePnP {

struct CvSolvePnPProps: Base::Props
{
	cv::Mat cameraMatrix;
	cv::Mat distCoeffs;

	/*!
	 * Load settings
	 *
	 * @param pt root property tree to load settings from
	 */
	virtual void load(const ptree & pt)
	{
		//cameraMatrix = str2mat(cv::Size(3, 3), pt.get("cameraMatrix"));
		//distCoeffs = str2mat(cv::Size(1, 5), pt.get("distCoeffs"));
	}

	/*!
	 * Save settings
	 *
	 * @param pt root property tree to save settings
	 */
	virtual void save(ptree & pt)
	{
	}
};

class CvSolvePnP_Processor: public Base::Component
{
public:
	CvSolvePnP_Processor(const std::string & n);
	virtual ~CvSolvePnP_Processor();

	virtual Base::Props * getProperties();
protected:
	/*!
	 * Method called when component is started
	 * \return true on success
	 */
	virtual bool onStart();

	/*!
	 * Method called when component is stopped
	 * \return true on success
	 */
	virtual bool onStop();

	/*!
	 * Method called when component is initialized
	 * \return true on success
	 */
	virtual bool onInit();

	/*!
	 * Method called when component is finished
	 * \return true on success
	 */
	virtual bool onFinish();

	/*!
	 * Method called when step is called
	 * \return true on success
	 */
	virtual bool onStep();

private:

	void onNewObject3D();

	CvSolvePnPProps props;

	Base::DataStreamInPtr <Types::Objects3D::Object3D> in_object3d;
	Base::DataStreamOut <Types::Objects3D::Object3D> out_object3d;

	Base::EventHandler<CvSolvePnP_Processor> h_onNewObject3D;
};

} // namespace CvSolvePnP

} // namespace Processors

#endif /* CVSOLVEPNP_PROCESSOR_HPP_ */
