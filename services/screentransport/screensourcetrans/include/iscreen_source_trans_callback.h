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

#ifndef OHOS_ISCREEN_SOURCE_TRANS_CALLBACK_H
#define OHOS_ISCREEN_SOURCE_TRANS_CALLBACK_H

#include <string>

namespace OHOS {
namespace DistributedHardware {
class IScreenSourceTransCallback {
public:
    virtual ~IScreenSourceTransCallback() = default;

    virtual void OnError(int32_t err, const std::string &content) = 0;
};
} // namespace DistributedHardware
} // namespace OHOS
#endif