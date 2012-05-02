// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_WEBUI_PREDICTORS_AUTOCOMPLETE_ACTION_PREDICTOR_UI_H_
#define CHROME_BROWSER_UI_WEBUI_PREDICTORS_AUTOCOMPLETE_ACTION_PREDICTOR_UI_H_
#pragma once

#include "content/public/browser/web_ui_controller.h"

class AutocompleteActionPredictorUI : public content::WebUIController {
 public:
  explicit AutocompleteActionPredictorUI(content::WebUI* web_ui);

 private:
  DISALLOW_COPY_AND_ASSIGN(AutocompleteActionPredictorUI);
};

#endif  // CHROME_BROWSER_UI_WEBUI_PREDICTORS_AUTOCOMPLETE_ACTION_PREDICTOR_UI_H_
