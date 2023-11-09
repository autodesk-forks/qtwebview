# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: LicenseRef-Qt-Commercial

add_subdirectory(webview)
add_subdirectory(quick)
add_subdirectory(plugins)
if(ANDROID)
    add_subdirectory(jar)
endif()
