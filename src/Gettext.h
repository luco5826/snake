#ifndef GETTEXT_H
#define GETTEXT_H

#include <libintl.h>
#include <locale.h>

#define _(STRING) gettext(STRING)

#endif