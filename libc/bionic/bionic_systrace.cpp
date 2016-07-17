/*
 * Copyright (C) 2014 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "private/bionic_lock.h"
#include "private/bionic_systrace.h"
#include "private/CachedProperty.h"

#include <cutils/trace.h> // For ATRACE_TAG_BIONIC.

static CachedProperty g_debug_atrace_tags_enableflags("debug.atrace.tags.enableflags");

void bionic_trace_begin(const char* message) {
    return;
    (void)message;
}

void bionic_trace_end() {
    return;
}

ScopedTrace::ScopedTrace(const char* message) : called_end_(false) {
  bionic_trace_begin(message);
}

ScopedTrace::~ScopedTrace() {
  End();
}

void ScopedTrace::End() {
  if (!called_end_) {
    bionic_trace_end();
    called_end_ = true;
  }
}
