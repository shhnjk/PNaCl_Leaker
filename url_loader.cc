// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This example demonstrates how to load content of the page into NaCl module.

#include <cstdio>
#include <string>
#include "ppapi/cpp/instance.h"
#include "ppapi/cpp/module.h"
#include "ppapi/cpp/url_loader.h"
#include "ppapi/cpp/var.h"

#include "url_loader_handler.h"


class URLLoaderInstance : public pp::Instance {
 public:
  explicit URLLoaderInstance(PP_Instance instance) : pp::Instance(instance) {
    std::string target_url = "https://test.shhnjk.com/secret.html";
    URLLoaderHandler* handler = URLLoaderHandler::Create(this, target_url);
    if (handler != NULL) {
      handler->Start();
    }
  }
  virtual ~URLLoaderInstance() {}
};

class URLLoaderModule : public pp::Module {
 public:
  URLLoaderModule() : pp::Module() {}
  virtual ~URLLoaderModule() {}

  // Create and return a URLLoaderInstance object.
  virtual pp::Instance* CreateInstance(PP_Instance instance) {
    return new URLLoaderInstance(instance);
  }
};

namespace pp {
Module* CreateModule() { return new URLLoaderModule(); }
}  // namespace pp
