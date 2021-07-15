
#ifndef INCLUDE_YANGCAPTURE_YANGVIDEOCAPTURE_H_
#define INCLUDE_YANGCAPTURE_YANGVIDEOCAPTURE_H_
#include "yangutil/sys/YangThread.h"
#include "yangutil/buffer/YangVideoBuffer.h"
#include "yangutil/sys/YangIni.h"
#include "yangutil/sys/YangLog.h"
#include <vector>
void yang_get_camera_indexs(std::vector<int> *pvs,std::string pcamindex);
class YangVideoCapture :public YangThread {
public:
	YangVideoCapture();
	virtual ~YangVideoCapture();
public:
     int cameraIndex;
     virtual int init()=0;
     virtual void setVideoCaptureStart()=0;
     virtual void setVideoCaptureStop()=0;
     virtual void setOutVideoBuffer(YangVideoBuffer *pbuf)=0;
     virtual void setPreVideoBuffer(YangVideoBuffer *pbuf)=0;
     virtual int getVideoCaptureState()=0;
     virtual void initstamp()=0;

     int m_isStart;
     void stop();
protected:
    void run();
    virtual void startLoop()=0;
    virtual void stopLoop()=0;
    YangVideoParam *m_para;
};

#endif /* INCLUDE_YANGCAPTURE_YANGVIDEOCAPTURE_H_ */
