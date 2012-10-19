#
#	Fig2dev Driver Library 
#
# Copyright (c) 1994 Micah Beck
# Parts Copyright (c) 1995-1999 Micah Beck
# Parts Copyright (c) 1995-2002 by Brian V. Smith
#
# Any party obtaining a copy of these files is granted, free of charge, a
# full and unrestricted irrevocable, world-wide, paid up, royalty-free,
# nonexclusive right and license to deal in this software and
# documentation files (the "Software"), including without limitation the
# rights to use, copy, modify, merge, publish and/or distribute copies of
# the Software, and to permit persons who receive copies from any such
# party to do so, with the only requirement being that this copyright
# notice remain intact.

if(PNG_LIBRARIES)
  set(PNG_SRCS readpng.c)
  add_definitions(-DUSE_PNG)
  include_directories(${PNG_INCLUDE_DIRS})
endif(PNG_LIBRARIES)
find_package(X11)
if(X11_Xpm_LIB)
  set(XPM_SRCS readxpm.c)
  add_definitions(-DUSE_XPM)
  include_directories(${X11_X11_INCLUDE_DIR})
endif(X11_Xpm_LIB)

add_definitions(-DBITMAPDIR=\"../bitmaps\")

set(trans_srcs
  genbox.c
  gencgm.c
  gendxf.c
  genepic.c
  gengbx.c
  genibmgl.c
  genlatex.c
  genmap.c
  genmf.c
  genpic.c
  genpictex.c
  genps.c
  genpdf.c
  genpstex.c
  genpstricks.c
  gentextyl.c
  gentk.c
  genptk.c
  gentpic.c
  genbitmaps.c
  genge.c
  genmp.c
  genemf.c
  gensvg.c
  genshape.c
  setfigfont.c
  psencode.c
  readpics.c
  readeps.c
  readgif.c
  readpcx.c
  readppm.c
  readpng.c
  readxpm.c
  readxbm.c
  readtif.c
  readjpg.c
  asc85ec.c
  ${PNG_SRCS} 
  ${XPM_SRCS}
  )

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/..
  ${CMAKE_CURRENT_SOURCE_DIR}/../..
  )

add_library(transfig SHARED ${trans_srcs})
target_link_libraries(transfig ${X11_Xpm_LIB} ${PNG_LIBRARIES})


# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8
