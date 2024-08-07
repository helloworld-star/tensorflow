/* Copyright 2024 The OpenXLA Authors.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "xla/stream_executor/host_memory_allocation.h"

#include <cstdint>

#include "xla/stream_executor/stream_executor.h"

namespace stream_executor {

HostMemoryAllocation::HostMemoryAllocation(void* ptr, uint64_t size,
                                           StreamExecutor* executor)
    : ptr_(ptr), size_(size), executor_(executor) {}

HostMemoryAllocation::~HostMemoryAllocation() {
  if (ptr_ != nullptr && executor_ != nullptr) {
    executor_->HostMemoryDeallocate(ptr_, size_);
  }
}

}  // namespace stream_executor
