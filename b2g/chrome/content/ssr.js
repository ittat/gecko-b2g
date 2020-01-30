/* -*- indent-tabs-mode: nil; js-indent-level: 2 -*- /
/* vim: set shiftwidth=2 tabstop=2 autoindent cindent expandtab: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

"use strict";

var Cc = Components.classes;
var Ci = Components.interfaces;
var Cu = Components.utils;
var Cr = Components.results;

// The load order is important here SettingsRequestManager _must_ be loaded
// prior to using SettingsListener otherwise there is a race in acquiring the
// lock and fulfilling it. If we ever move SettingsListener or this file down in
// the load order of shell.html things will likely break.
Cu.import('resource://gre/modules/SettingsRequestManager.jsm');
Cu.import('resource://gre/modules/XPCOMUtils.jsm');
Cu.import('resource://gre/modules/Services.jsm');
Cu.import('resource://gre/modules/AppConstants.jsm');


//XPCOMUtils.defineLazyGetter(this, "cpmm", function() {
//  return Cc["@mozilla.org/childprocessmessagemanager;1"]
//           .getService(Ci.nsIMessageSender);
//});




window.addEventListener('test-gaia2gecko', function() {
  // Get the command line arguments that were passed to the b2g client
  debug('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% ' + Services.prefs.getCharPref("b2g.system_manifest_url"));
});

//function eventHandler(event) {
//  if (event.type == fullscreenchange) {
//    /* handle a full screen toggle */
//  } else /* fullscreenerror */ {
//    /* handle a full screen toggle error */
//  }
//}

// =================== Mono Audio ======================

  //Services.prefs.setBoolPref('accessibility.monoaudio.enable', value);
  //Services.prefs.getCharPref("b2g.system_manifest_url")





