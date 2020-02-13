#ifndef dataStructures_h
#define dataStructures_h

#include <vector>
#include <deque>
#include <opencv2/core.hpp>


struct DataFrame { // represents the available sensor information at the same time instance

    cv::Mat cameraImg; // camera image

    std::vector<cv::KeyPoint> keypoints; // 2D keypoints within camera image
    cv::Mat descriptors; // keypoint descriptors
    std::vector<cv::DMatch> kptMatches; // keypoint matches between previous and current frame
};

template<typename T>
struct LeakyStack: public std::deque<T>
{
    std::deque<T> data;
    int max_size;

    T push_back(T element){
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
