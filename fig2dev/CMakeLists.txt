# Fig2dev : General Fig code translation program
# Copyright (c) 1991 Micah Beck
# Parts Copyright (c) 1995-2002 by Brian V. Smith
# Parts Copyright (c) 1999 by T. Sato

# Any party obtaining a copy of these files is granted, free of charge, a
# full and unrestricted irrevocable, world-wide, paid up, royalty-free,
# nonexclusive right and license to deal in this software and
# documentation files (the "Software"), including without limitation the
# rights to use, copy, modify, merge, publish and/or distribute copies of
# the Software, and to permit persons who receive copies from any such
# party to do so, with the only requirement being that this copyright
# notice remain intact.

# Need libtrans
add_subdirectory(dev)

add_definitions(-DRGB_FILE=\"rgb.txt\")

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/..
  )

set(fig2dev_SRCS
  getopt.c
  fig2dev.c
  psfonts.c
  iso2tex.c
  arrow.c
  bound.c
  colors.c
  trans_spline.c
  free.c
  read.c
  read1_3.c
  latex_line.c
  localmath.c
  )

add_executable(xfig_fig2dev ${fig2dev_SRCS})
target_link_libraries(xfig_fig2dev ${PNG_LIBRARIES} ${M_LIBRARY} transfig)

# Local Variables:
# tab-width: 8
# mode: cmake
# indent-tabs-mode: t
# End:
# ex: shiftwidth=2 tabstop=8
