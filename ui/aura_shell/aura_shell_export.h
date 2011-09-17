// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_AURA_SHELL_AURA_SHELL_EXPORT_H
#define UI_AURA_SHELL_AURA_SHELL_EXPORT_H
#pragma once

// Defines AURA_SHELL_EXPORT so that functionality implemented by the aura_shell
// module can be exported to consumers.

#if defined(COMPONENT_BUILD)
#if defined(WIN32)

#if defined(AURA_SHELL_IMPLEMENTATION)
#define AURA_SHELL_EXPORT __declspec(dllexport)
#else
#define AURA_SHELL_EXPORT __declspec(dllimport)
#endif  // defined(AURA_SHELL_IMPLEMENTATION)

#else  // defined(WIN32)
#define AURA_SHELL_EXPORT __attribute__((visibility("default")))
#endif

#else  // defined(COMPONENT_BUILD)
#define AURA_SHELL_EXPORT
#endif

#endif  // UI_AURA_SHELL_AURA_SHELL_EXPORT_H

