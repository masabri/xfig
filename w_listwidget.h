/*
 * FIG : Facility for Interactive Generation of figures
 * Copyright (c) 1989-2007 by Brian V. Smith
 *
 * Any party obtaining a copy of these files is granted, free of charge, a
 * full and unrestricted irrevocable, world-wide, paid up, royalty-free,
 * nonexclusive right and license to deal in this software and documentation
 * files (the "Software"), including without limitation the rights to use,
 * copy, modify, merge, publish distribute, sublicense and/or sell copies of
 * the Software, and to permit persons who receive copies from any such
 * party to do so, with the only requirement being that the above copyright
 * and this permission notice remain intact.
 *
 */

/* FigList widget public header file */

#ifndef _FigList_h
#define _FigList_h

#ifdef XAW3D
#include <X11/Xaw3d/Simple.h>
#else /* XAW3D */
#include <X11/Xaw/Simple.h>
#endif /* XAW3D */
#include <X11/Xfuncproto.h>

extern WidgetClass figListWidgetClass;

typedef struct	_FigListClassRec *FigListWidgetClass;
typedef struct	_FigListRec	 *FigListWidget;

#endif /* _FigList_h */

/* DON'T ADD ANYTHING AFTER THIS #endif */
