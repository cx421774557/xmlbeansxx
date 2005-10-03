/*
    Copyright 2004-2005 TouK s.c.
    
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License. */
    
#include "SchemaTypeImpl.h"
#include "Null.h"
#include <log4cxx/logger.h>
namespace xmlbeansxx {
log4cxx::LoggerPtr SchemaTypeImpl_I::LOG = log4cxx::Logger::getLogger("xmlbeansxx.SchemaTypeImpl");

void SchemaTypeImpl_I::init() {
    fractionDigits=-1;
    contentType = SchemaType::MIXED_CONTENT;
    createRawXmlObject = NULL;
}

SchemaTypeImpl_I::SchemaTypeImpl_I(const std::type_info &classTypeInfo): classTypeInfo(classTypeInfo) {
    init();
}

SchemaProperty SchemaTypeImpl_I::getAttributeProperty(const QName &name) {
    PropertyMap::const_iterator it=attributes.find(name);
    if (it==attributes.end()) return Null();
    else return it->second;
}

SchemaProperty SchemaTypeImpl_I::getElementProperty(const QName &name) {
    PropertyMap::const_iterator it=elements.find(name);
    if (it==elements.end()) return Null();
    else return it->second;
}

}