// Copyright (c) 2009 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/common/gtk_util.h"

#include <gtk/gtk.h>

#include "base/linux_util.h"
#include "third_party/skia/include/core/SkBitmap.h"

namespace {

// Callback used in RemoveAllChildren.
void RemoveWidget(GtkWidget* widget, gpointer container) {
  gtk_container_remove(GTK_CONTAINER(container), widget);
}

}  // namespace

namespace event_utils {

WindowOpenDisposition DispositionFromEventFlags(guint event_flags) {
  if ((event_flags & GDK_BUTTON2_MASK) || (event_flags & GDK_CONTROL_MASK)) {
    return (event_flags & GDK_SHIFT_MASK) ?
        NEW_FOREGROUND_TAB : NEW_BACKGROUND_TAB;
  }

  if (event_flags & GDK_SHIFT_MASK)
    return NEW_WINDOW;
  return false /*event.IsAltDown()*/ ? SAVE_TO_DISK : CURRENT_TAB;
}

}  // namespace event_utils

namespace gtk_util {

GtkWidget* CreateGtkBorderBin(GtkWidget* child, const GdkColor* color,
                              int top, int bottom, int left, int right) {
  // Use a GtkEventBox to get the background painted.  However, we can't just
  // use a container border, since it won't paint there.  Use an alignment
  // inside to get the sizes exactly of how we want the border painted.
  GtkWidget* ebox = gtk_event_box_new();
  if (color)
    gtk_widget_modify_bg(ebox, GTK_STATE_NORMAL, color);
  GtkWidget* alignment = gtk_alignment_new(0.0, 0.0, 1.0, 1.0);
  gtk_alignment_set_padding(GTK_ALIGNMENT(alignment), top, bottom, left, right);
  gtk_container_add(GTK_CONTAINER(alignment), child);
  gtk_container_add(GTK_CONTAINER(ebox), alignment);
  return ebox;
}

void RemoveAllChildren(GtkWidget* container) {
  gtk_container_foreach(GTK_CONTAINER(container), RemoveWidget, container);
}

}  // namespace gtk_util
