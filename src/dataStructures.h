#ifndef dataStructures_h
#define dataStructures_h

#include <vector>
#include <string>
#include <deque>
#include <opencv2/core.hpp>


struct DataFrame { // represents the available sensor information at the same time instance

    cv::Mat cameraImg; // camera image

    std::vector<cv::KeyPoint> keypoints; // 2D keypoints within camera image
    cv::Mat descriptors; // keypoint descriptors
    std::vector<cv::DMatch> kptMatches; // keypoint matches between previous and current frame
};

struct DetectorStats{
    std::string detector;
    int num_keypoints;
    float neighb_size_mean;
    float neighb_size_var;
    size_t image_num;
};

struct MatchStats{
    std::string detector;
    std::string descriptor;
    int num_matches;
    int image_num;
    float detector_time;
    float descriptor_time;
};


template<typename T>
struct LeakyStack
{
    std::deque<T> data;
    int max_size;

    void push_back(T element){
        data.push_back(element);
        if(data.size()> max_size)
            data.pop_front();
    }

    // support Python-style negative indexing
    typename std::deque<T>::iterator begin(){
        return data.begin();
    }

    typename std::deque<T>::iterator end(){
        return data.end();
    }

    int size(){
        return data.size();
    }

    LeakyStack<T>(int max_size): max_size(max_size){};

};
#endif /* dataStructures_h */
