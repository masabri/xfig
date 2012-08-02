# Minimum required version of CMake
cmake_minimum_required(VERSION 2.8)
if(COMMAND CMAKE_POLICY)
  CMAKE_POLICY(SET CMP0003 NEW)
endif(COMMAND CMAKE_POLICY)

# set CMake project name
project(XFIG)

if(XFIG_IS_SUBBUILD)
	set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/CMake")
else(XFIG_IS_SUBBUILD)
	set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake;${CMAKE_MODULE_PATH}")
endif(XFIG_IS_SUBBUILD)

find_package(X11)
if(X11_Xpm_LIB)
	add_definitions(-DUSE_XPM)
	add_definitions(-DUSE_XPM_ICON)
endif(X11_Xpm_LIB)

find_library(XAW3D_LIB NAMES Xaw3d)
if(NOT "${XAW3D_LIB}" MATCHES "NOTFOUND")
	add_definitions(-DXAW3D)
	add_definitions(-DXAW3D1_5E)
	add_definitions(-DXAW_INTERNATIONALIZATION)
endif(NOT "${XAW3D_LIB}" MATCHES "NOTFOUND")

find_package(JPEG)
if(JPEG_LIBRARIES)
	add_definitions(-DUSE_JPEG)
endif(JPEG_LIBRARIES)

find_package(PNG)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_BINARY_DIR}
  ${JPEG_INCLUDE_DIR}
  ${PNG_INCLUDE_DIR}
  ${X11_X11_INCLUDE_DIR}
  )

set(XFIG_VERSION "3.2.5b")

set(OBJ_LIB_DIR "${CMAKE_INSTALL_PREFIX}/share/xfig/Libraries")
add_definitions(-DOBJLIBDIR=\"${OBJ_LIB_DIR}\")

set(XFIG_LIB_DIR "${CMAKE_INSTALL_PREFIX}/share/xfig")
add_definitions(-DXFIGLIBDIR=\"${XFIG_LIB_DIR}\")

set(XFIG_DOC_DIR "${CMAKE_INSTALL_PREFIX}/share/doc/xfig-${XFIG_VERSION}")
add_definitions(-DXFIGDOCDIR=\"${XFIG_DOC_DIR}\")

add_definitions(-DPRINTCAP=\"/etc/printcap\")
add_definitions(-DCOMP_LED=3)
add_definitions(-DFUNCPROTO=15)
add_definitions(-DNARROWPROTO)
add_definitions(-DNEWARROWTYPES)
add_definitions(-DUSE_INLINE)
add_definitions(-DI18N)

set(CMAKE_C_FLAGS "-g")

set(XFIG_SRCS
	d_arcbox.c
	d_arc.c
	d_box.c
	d_ellipse.c
	d_line.c
	d_picobj.c
	d_regpoly.c
	d_spline.c
	d_subspline.c
	d_text.c
	e_addpt.c
	e_align.c
	e_arrow.c
	e_break.c
	e_chop.c
	e_compound.c
	e_convert.c
	e_copy.c
	e_delete.c
	e_deletept.c
	e_edit.c
	e_flip.c
	e_glue.c
	e_joinsplit.c
	e_measure.c
	e_move.c
	e_movept.c
	e_placelib.c
	e_rotate.c
	e_scale.c
	e_tangent.c
	e_update.c
	f_load.c
	f_neuclrtab.c
	f_picobj.c
	f_read.c
	f_readeps.c
	f_readgif.c
	f_readjpg.c
	f_readold.c
	f_readpcx.c
	f_readpng.c
	f_readppm.c
	f_readtif.c
	f_readxbm.c
	f_readxpm.c
	f_save.c
	f_util.c
	f_wrpcx.c
	f_wrpng.c
	main.c
	mode.c
	object.c
	resources.c
	SimpleMenu.c
	SmeBSB.c
	SmeCascade.c
	u_bound.c
	u_create.c
	u_drag.c
	u_draw.c
	#u_draw_spline.c
	u_elastic.c
	u_error.c
	u_fonts.c
	u_free.c
	u_geom.c
	u_list.c
	u_markers.c
	u_pan.c
	u_print.c
	u_quartic.c
	u_redraw.c
	u_scale.c
	u_search.c
	u_smartsearch.c
	u_translate.c
	u_undo.c
	w_browse.c
	w_canvas.c
	w_capture.c
	w_cmdpanel.c
	w_color.c
	w_cursor.c
	w_digitize.c
	w_dir.c
	w_drawprim.c
	w_export.c
	w_file.c
	w_fontbits.c
	w_fontpanel.c
	w_grid.c
	w_help.c
	w_i18n.c
	w_icons.c
	w_indpanel.c
	w_intersect.c
	w_keyboard.c
	w_layers.c
	w_library.c
	w_listwidget.c
	w_menuentry.c
	w_modepanel.c
	w_mousefun.c
	w_msgpanel.c
	w_print.c
	w_rottext.c
	w_rulers.c
	w_setup.c
	w_snap.c
	w_srchrepl.c
	w_style.c
	w_util.c
	w_zoom.c
  )

add_executable(xfig ${XFIG_SRCS})
target_link_libraries(xfig ${JPEG_LIBRARIES} ${PNG_LIBRARIES} ${X11_X11_LIB}
	${X11_Xt_LIB} ${X11_Xpm_LIB} ${X11_Xi_LIB} ${XAW3D_LIB})
