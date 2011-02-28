/*
 * This file is part of crash-reporter
 *
 * Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
 *
 * Contact: Ville Ilvonen <ville.p.ilvonen@nokia.com>
 * Author: Riku Halonen <riku.halonen@nokia.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef CREPORTERUPLOADDIALOGPLUGIN_H
#define CREPORTERUPLOADDIALOGPLUGIN_H

// User includes.

#include "creporterdialogplugininterface.h"
#include "creporterdialogserverinterface.h"

// Forward declarations.

class CReporterUploadDialogPluginPrivate;

/*!
  * @class CReporterUploadDialogPlugin
  * @brief This class implements dialog plugin interface.
  *
  * @sa CReporterDialogPluginInterface
  */
class CReporterUploadDialogPlugin : public CReporterDialogPluginInterface
{
    Q_OBJECT
    Q_INTERFACES(CReporterDialogPluginInterface)

    public:
        //! @reimp
        virtual void initialize(CReporterDialogServerInterface  *server);
        //! @reimp
        virtual void destroy();
        //! @reimp
        virtual bool isInitialized() const;
        //! @reimp
        virtual QString name() const;
        //! @reimp
        virtual bool requestDialog(const QVariantList &arguments);
        //! @reimp
        virtual bool isActive() const;
        //! @reimp
        virtual bool isVisible() const;

    private Q_SLOTS:
        /*!
          * @brief Called, when user interacts with the dialog.
          *
          * @param buttonId To identify pressed button.
          */
        void actionPerformed(int buttonId);

        /*!
          * @brief Called, when user has dismissed the dialog by tapping outside of it.
          */
        void dialogRejected();

        /*!
          * @brief Called, when upload engine has finished uploading.
          *
          * @param error Error code.
          * @param sent Number of files uploaded succesfully.
          * @param total Number of files requested to send.
          */
        void engineFinished(int error, int sent, int total);

        /*!
          * @brief Called, when dialog has been destroyed and dialog can be closed.
          *
          */
        void dialogFinished();

        /*!
          * @brief Called, when dialog has finished its appearance transition.
          *
          */
        void dialogAppeared();

    private:
       Q_DECLARE_PRIVATE( CReporterUploadDialogPlugin )
       //! @arg Pointer to private data.
       CReporterUploadDialogPluginPrivate *d_ptr;
#ifdef CREPORTER_UNIT_TEST
       friend class Ut_CReporterUploadDialogPlugin;
#endif // CREPORTER_UNIT_TEST
};

#endif // CREPORTERUPLOADDIALOGPLUGIN_H

// End of file.
