/*
 *  File:             shape.h
 *  Project Main:     boxes.c
 *  Date created:     June 23, 1999 (Wednesday, 13:45h)
 *  Author:           Copyright (C) 1999 Thomas Jensen <boxes@thomasjensen.com>
 *  Language:         ANSI C
 *  Web Site:         http://boxes.thomasjensen.com/
 *  Purpose:          Shape handling and information functions
 *
 *  License: o This program is free software; you can redistribute it and/or
 *             modify it under the terms of the GNU General Public License as
 *             published by the Free Software Foundation; either version 2 of
 *             the License, or (at your option) any later version.
 *           o This program is distributed in the hope that it will be useful,
 *             but WITHOUT ANY WARRANTY; without even the implied warranty of
 *             MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *             GNU General Public License for more details.
 *           o You should have received a copy of the GNU General Public
 *             License along with this program; if not, write to the Free
 *             Software Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 *             MA 02111-1307  USA
 *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

#ifndef SHAPE_H
#define SHAPE_H


typedef enum {
    NW, NNW, N, NNE, NE, ENE, E, ESE, SE, SSE, S, SSW, SW, WSW, W, WNW
} shape_t;

extern char *shape_name[];

#define ANZ_SHAPES 16

#define SHAPES_PER_SIDE 5
#define ANZ_SIDES       4
#define ANZ_CORNERS     4

extern shape_t north_side[SHAPES_PER_SIDE];  /* groups of shapes, clockwise */
extern shape_t  east_side[SHAPES_PER_SIDE];
extern shape_t south_side[SHAPES_PER_SIDE];
extern shape_t  west_side[SHAPES_PER_SIDE];
extern shape_t corners[ANZ_CORNERS];
extern shape_t *sides[ANZ_SIDES];


typedef struct {
    char **chars;
    size_t height;
    size_t width;
    int    elastic;          /* elastic is used only in orginial definition */
} sentry_t;

#define SENTRY_INITIALIZER (sentry_t) {NULL, 0, 0, 0}



int genshape (const size_t width, const size_t height, char ***chars);
void freeshape (sentry_t *shape);

shape_t findshape (const sentry_t *sarr, const int num);
int on_side (const shape_t s, const int idx);

int isempty (const sentry_t *shape);
int isdeepempty (const sentry_t *shape);

size_t highest (const sentry_t *sarr, const int n, ...);
size_t widest (const sentry_t *sarr, const int n, ...);

shape_t leftmost (const int aside, const int cnt);

int empty_side (sentry_t *sarr, const int aside);



#endif /*SHAPE_H*/

/*EOF*/                                          /* vim: set cindent sw=4: */
