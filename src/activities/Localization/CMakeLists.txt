if ( NOT ( ${TargetPlatform} STREQUAL "robot" AND ${RobotPlatform} STREQUAL "nao" ) )
    return()
endif ( NOT ( ${TargetPlatform} STREQUAL "robot" AND ${RobotPlatform} STREQUAL "nao" ) )


include( ../../hal/robot/nao-1.6.0/bootstrap.cmake )

include_directories( ../../../external/PracticalSocket)

set ( ActivityName Localization )

set ( ActivitySrcs  Localization
newran/newran.h newran/newran.cpp newran/include.h newran/boolean.h newran/extreal.h newran/extreal.cpp newran/myexcept.cpp newran/myexcept.h
Kutils.h Kutils.cpp
KLocalization.h KLocalization.cpp ../../../external/PracticalSocket/PracticalSocket.cpp
)

include ( ../activTemplate.cmake )

use_lib(${ActivityName} ALCOMMON ALVALUE ALMATH LIBCORE TOOLS )

target_link_libraries ( ${ActivityName}   NaoQiDep )

