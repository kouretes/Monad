message ( STATUS "" )
message ( STATUS " _..::: Configuring Statecharts :::.._ " )
message ( STATUS "" )

file ( GLOB FilesInDir . * )

foreach ( afile ${FilesInDir} )
  if ( IS_DIRECTORY ${afile} )
    set ( theSubDirs ${theSubDirs}  ${afile}  )
    message ( STATUS "Statechart ${afile} detected and added to the building tree" )
  endif ( IS_DIRECTORY ${afile} )
endforeach ( afile )


foreach ( subdir ${theSubDirs} )
   add_subdirectory( ${subdir} )
endforeach ( subdir ${theSubDirs} )

set ( TargetLinkLibraries ${TargetLinkLibraries} ${StatechartLibraries} PARENT_SCOPE)
