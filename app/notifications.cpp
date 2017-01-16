/*
 * Fedora Media Writer
 * Copyright (C) 2017 Martin Bříza <mbriza@redhat.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "notifications.h"

#include <QDebug>

#ifdef __linux

# include <QDBusInterface>

void Notifications::notify(const QString &title, const QString &body) {
    QDBusInterface notifications("org.freedesktop.Notifications", "/org/freedesktop/Notifications", "org.freedesktop.Notifications", QDBusConnection::sessionBus());
    auto reply = notifications.call("Notify", "Fedora Media Writer", 0U, "mediawriter", title, body, QStringList{}, QVariantMap{}, -1);
    qCritical() << reply.arguments();
}

#endif // __linux

#ifdef __APPLE__

void Notifications::notify(const QString &title, const QString &body) {
    Q_UNUSED(title); Q_UNUSED(body);
}

#endif // APPLE

#ifdef _WIN32

void Notifications::notify(const QString &title, const QString &body) {
    Q_UNUSED(title); Q_UNUSED(body);
}

#endif // _WIN32


