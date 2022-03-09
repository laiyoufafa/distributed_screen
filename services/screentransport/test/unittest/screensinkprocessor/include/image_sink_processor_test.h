/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef IMAGE_SINK_DECODER_TEST_H
#define IMAGE_SINK_DECODER_TEST_H

#include <gtest/gtest.h>

#define private public
#include "image_sink_processor.h"
#undef private
#include "screentrans_test_utils.h"
#include "iscreen_channel_listener.h"

namespace OHOS {
namespace DistributedHardware {
class ImageSinkProcessorTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();

    VideoParam param_;
    std::shared_ptr<ImageSinkProcessor> processor_;
    std::shared_ptr<IImageSinkProcessorListener> imageListener_;
};
}
}
#endif