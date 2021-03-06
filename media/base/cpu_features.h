// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file provide utility functions to check CPU features such as SSE2,
// NEON.

#ifndef MEDIA_BASE_CPU_FEATURES_H_
#define MEDIA_BASE_CPU_FEATURES_H_

namespace media {

// Returns true if CPU has MMX support.
bool hasMMX();

// Returns true if CPU has SSE support.
bool hasSSE();

// Returns true if CPU has SSE2 support.
bool hasSSE2();

// Returns true if CPU supports SSE2, SSE3, and SSSE3.
bool hasSSSE3();

}  // namespace media

#endif  // MEDIA_BASE_CPU_FEATURES_H_
