#include<boost/shared_ptr.hpp>
#include<boost/any.hpp>
#include<map>
#include<string>

#include "ObjectRepository.h"

boost::shared_ptr<std::map<std::string, boost::any>> ObjectRepository::rep_(new std::map<std::string, boost::any>());