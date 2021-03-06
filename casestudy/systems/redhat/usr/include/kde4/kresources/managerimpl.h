/*
    This file is part of libkresources.

    Copyright (c) 2002 Tobias Koenig <tokoe@kde.org>
    Copyright (c) 2002 Jan-Pascal van Best <janpascal@vanbest.org>
    Copyright (c) 2003 Cornelius Schumacher <schumacher@kde.org>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/
#ifndef KRESOURCES_MANAGERIMPL_H
#define KRESOURCES_MANAGERIMPL_H

#include "resource.h"
#include <QtCore/QString>

class KConfig;

namespace KRES {

class Resource;
class ManagerNotifier;

/**
  @internal

  Do not use this class directly. Use ResourceManager instead
*/
class KRESOURCES_EXPORT ManagerImpl : public QObject
{
  Q_OBJECT
  public:
    ManagerImpl( ManagerNotifier *, const QString &family );
    ~ManagerImpl();

    void readConfig( KConfig * );
    void writeConfig( KConfig * );

    void add( Resource *resource );
    void remove( Resource *resource );
    void change( Resource *resource );

    Resource *standardResource();
    void setStandardResource( Resource *resource );

    void setActive( Resource *resource, bool active );

    Resource::List *resourceList();

    QList<Resource *> resources();

    // Get only active or passive resources
    QList<Resource *> resources( bool active );

    QStringList resourceNames();

    static QString defaultConfigFile( const QString &family );

  Q_SIGNALS:
    void signalKResourceAdded( QString managerId, QString resourceId );
    void signalKResourceModified( QString managerId, QString resourceId );
    void signalKResourceDeleted( QString managerId, QString resourceId );

  private Q_SLOTS:
    // dbus calls
    void dbusKResourceAdded( const QString &managerId,
                             const QString &resourceId );
    void dbusKResourceModified( const QString &managerId,
                                const QString &resourceId );
    void dbusKResourceDeleted( const QString &managerId,
                               const QString &resourceId );

  private:
    void createStandardConfig();

    Resource *readResourceConfig( const QString &identifier, bool checkActive );
    void writeResourceConfig( Resource *resource, bool checkActive );

    void removeResource( Resource *resource );
    Resource *getResource( Resource *resource );
    Resource *getResource( const QString &identifier );

    class ManagerImplPrivate;
    ManagerImplPrivate *const d;
};

}

#endif
