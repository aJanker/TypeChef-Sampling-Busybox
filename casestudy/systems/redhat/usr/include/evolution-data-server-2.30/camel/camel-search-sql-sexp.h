/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  Copyright (C) 2008 Novell, Inc. (www.novell.com)
 *
 *  Authors: Srinivsa Ragavan <sragavan@novell.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 2 of the GNU Lesser General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef _CAMEL_SEARCH_SQL_SEXP_H
#define _CAMEL_SEARCH_SQL_SEXP_H

G_BEGIN_DECLS

/* FIXME: Weird naming, since, I want both parsers to be there for some time.*/
gchar * camel_sexp_to_sql_sexp (const gchar *sexp);

G_END_DECLS

#endif /* _CAMEL_SEARCH_SQL_H */
