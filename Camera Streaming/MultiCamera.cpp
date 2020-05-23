/****************************************************************************
*  https://putuyuwono.wordpress.com/2015/05/29/multi-thread-multi-camera-capture-using-opencv/
*
*  https://github.com/jckarter/tbb  install TBB
* sudo apt-get install libtbb-dev
****************************************************************************/

#include "CameraStreamer.hpp"
#include "opencv2/highgui.hpp"

int main( void  )
{
    //IP camera URLs
        vector<string> capture_source =
        {
            "https://thbcctv16.thb.gov.tw/T9-72K+450?resolution=CIF_352X288",  //礁溪喜互惠
  //        "rtmp://203.66.14.80:1935/live/KI00PNZ2VNOKT3AQ01B1_1" ,
  //        "rtsp://184.72.239.149/vod/mp4:BigBuckBunny_175k.mov",
//            "rtsp://170.93.143.139/rtplive/470011e600ef003a004ee33696235daa",
        //    "rtsp://quicktime.tc.columbia.edu:554/users/lrf10/movies/sixties.mov",
//            "rtsp://rtsp-v3-spbtv.msk.spbtv.com/spbtv_v3_1/214_110.sdp"
  //         "rtsp://192.168.2.100/profile2/media.smp",
  //         "rtsp://192.168.0.100/profile2/media.smp"

        } ;

        vector< int > capture_source_id =
        {
            0, 1
        } ;

    //USB Camera indices
        vector<int> capture_index = { 0, 1 };

    //Highgui window titles
        vector<string> label ;
        for (int i = 0; i < capture_source.size(); i++)
        {
            string title = "CCTV " + to_string(i);
            label.push_back(title);
        }

    //Make an instance of CameraStreamer
  //      CameraStreamer cam(capture_source) ;
       CameraStreamer cam(capture_source) ;

        while (waitKey(20) != 27)
        {
        //Retrieve frames from each camera capture thread
            for (int i = 0; i < capture_source.size( ); i++)
            {
                Mat frame ;
//Pop frame from queue and check if the frame is valid
                if (cam.frame_queue[i]->try_pop(frame))
                {
                //Show frame on Highgui window
                    imshow(label[i], frame) ;
                }
            }
        }
        return 0 ;
}
