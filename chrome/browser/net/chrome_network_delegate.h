// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_NET_CHROME_NETWORK_DELEGATE_H_
#define CHROME_BROWSER_NET_CHROME_NETWORK_DELEGATE_H_
#pragma once

#include "base/basictypes.h"
#include "base/compiler_specific.h"
#include "base/memory/ref_counted.h"
#include "net/base/network_delegate.h"

class ExtensionEventRouterForwarder;
class ExtensionInfoMap;
class PrefService;
template<class T> class PrefMember;

typedef PrefMember<bool> BooleanPrefMember;

// ChromeNetworkDelegate is the central point from within the chrome code to
// add hooks into the network stack.
class ChromeNetworkDelegate : public net::NetworkDelegate {
 public:
  // If |profile| is NULL, events will be broadcasted to all profiles, otherwise
  // they will only be sent to the specified profile.
  // |enable_referrers| should be initialized on the UI thread (see below)
  // beforehand. This object's owner is responsible for cleaning it up
  // at shutdown.
  ChromeNetworkDelegate(
      ExtensionEventRouterForwarder* event_router,
      ExtensionInfoMap* extension_info_map,
      void* profile,
      BooleanPrefMember* enable_referrers);
  virtual ~ChromeNetworkDelegate();

  // Binds |enable_referrers| to |pref_service| and moves it to the IO thread.
  // This method should be called on the UI thread.
  static void InitializeReferrersEnabled(BooleanPrefMember* enable_referrers,
                                         PrefService* pref_service);

 private:
  // NetworkDelegate methods:
  virtual int OnBeforeURLRequest(net::URLRequest* request,
                                 net::CompletionCallback* callback,
                                 GURL* new_url) OVERRIDE;
  virtual int OnBeforeSendHeaders(net::URLRequest* request,
                                  net::CompletionCallback* callback,
                                  net::HttpRequestHeaders* headers) OVERRIDE;
  virtual void OnRequestSent(uint64 request_id,
                             const net::HostPortPair& socket_address,
                             const net::HttpRequestHeaders& headers);
  virtual void OnBeforeRedirect(net::URLRequest* request,
                                const GURL& new_location);
  virtual void OnResponseStarted(net::URLRequest* request);
  virtual void OnRawBytesRead(const net::URLRequest& request, int bytes_read);
  virtual void OnCompleted(net::URLRequest* request);
  virtual void OnURLRequestDestroyed(net::URLRequest* request);
  virtual void OnHttpTransactionDestroyed(uint64 request_id);
  virtual void OnPACScriptError(int line_number, const string16& error);

  scoped_refptr<ExtensionEventRouterForwarder> event_router_;
  void* profile_;

  scoped_refptr<ExtensionInfoMap> extension_info_map_;

  // Weak, owned by our owner.
  BooleanPrefMember* enable_referrers_;

  DISALLOW_COPY_AND_ASSIGN(ChromeNetworkDelegate);
};

#endif  // CHROME_BROWSER_NET_CHROME_NETWORK_DELEGATE_H_
