// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

function runTests() {
  var getURL = chrome.extension.getURL;
  chrome.tabs.create({"url": "about:blank"}, function(tab) {
    var tabId = tab.id;

    chrome.test.runTests([
      // Opens a new tab from javascript.
      function openTab() {
        expect([
          { label: "a-onBeforeNavigate",
            event: "onBeforeNavigate",
            details: { frameId: 0,
                       tabId: 0,
                       timeStamp: 0,
                       url: getURL('openTab/a.html') }},
          { label: "a-onCommitted",
            event: "onCommitted",
            details: { frameId: 0,
                       tabId: 0,
                       timeStamp: 0,
                       transitionQualifiers: [],
                       transitionType: "link",
                       url: getURL('openTab/a.html') }},
          { label: "a-onDOMContentLoaded",
            event: "onDOMContentLoaded",
            details: { frameId: 0,
                       tabId: 0,
                       timeStamp: 0,
                       url: getURL('openTab/a.html') }},
          { label: "a-onCompleted",
            event: "onCompleted",
            details: { frameId: 0,
                       tabId: 0,
                       timeStamp: 0,
                       url: getURL('openTab/a.html') }},
          { label: "a-onCreatedNavigationTarget",
            event: "onCreatedNavigationTarget",
            details: { sourceFrameId: 0,
                       sourceTabId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       url: getURL('openTab/b.html') }},
          { label: "b-onBeforeNavigate",
            event: "onBeforeNavigate",
            details: { frameId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       url: getURL('openTab/b.html') }},
          { label: "b-onCommitted",
            event: "onCommitted",
            details: { frameId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       transitionQualifiers: [],
                       transitionType: "link",
                       url: getURL('openTab/b.html') }},
          { label: "b-onDOMContentLoaded",
            event: "onDOMContentLoaded",
            details: { frameId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       url: getURL('openTab/b.html') }},
          { label: "b-onCompleted",
            event: "onCompleted",
            details: { frameId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       url: getURL('openTab/b.html') }}],
          [ navigationOrder("a-"),
            navigationOrder("b-"),
            ["a-onDOMContentLoaded", "a-onCreatedNavigationTarget",
             "b-onBeforeNavigate"]]);
        chrome.tabs.update(tabId, { url: getURL('openTab/a.html') });
      },

      // Opens a new tab from javascript within an iframe.
      function openTabFrame() {
        expect([
          { label: "c-onBeforeNavigate",
            event: "onBeforeNavigate",
            details: { frameId: 0,
                       tabId: 0,
                       timeStamp: 0,
                       url: getURL('openTab/c.html') }},
          { label: "c-onCommitted",
            event: "onCommitted",
            details: { frameId: 0,
                       tabId: 0,
                       timeStamp: 0,
                       transitionQualifiers: [],
                       transitionType: "link",
                       url: getURL('openTab/c.html') }},
          { label: "c-onDOMContentLoaded",
            event: "onDOMContentLoaded",
            details: { frameId: 0,
                       tabId: 0,
                       timeStamp: 0,
                       url: getURL('openTab/c.html') }},
          { label: "c-onCompleted",
            event: "onCompleted",
            details: { frameId: 0,
                       tabId: 0,
                       timeStamp: 0,
                       url: getURL('openTab/c.html') }},
          { label: "a-onBeforeNavigate",
            event: "onBeforeNavigate",
            details: { frameId: 1,
                       tabId: 0,
                       timeStamp: 0,
                       url: getURL('openTab/a.html') }},
          { label: "a-onCommitted",
            event: "onCommitted",
            details: { frameId: 1,
                       tabId: 0,
                       timeStamp: 0,
                       transitionQualifiers: [],
                       transitionType: "auto_subframe",
                       url: getURL('openTab/a.html') }},
          { label: "a-onDOMContentLoaded",
            event: "onDOMContentLoaded",
            details: { frameId: 1,
                       tabId: 0,
                       timeStamp: 0,
                       url: getURL('openTab/a.html') }},
          { label: "a-onCompleted",
            event: "onCompleted",
            details: { frameId: 1,
                       tabId: 0,
                       timeStamp: 0,
                       url: getURL('openTab/a.html') }},
          { label: "a-onCreatedNavigationTarget",
            event: "onCreatedNavigationTarget",
            details: { sourceFrameId: 1,
                       sourceTabId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       url: getURL('openTab/b.html') }},
          { label: "b-onBeforeNavigate",
            event: "onBeforeNavigate",
            details: { frameId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       url: getURL('openTab/b.html') }},
          { label: "b-onCommitted",
            event: "onCommitted",
            details: { frameId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       transitionQualifiers: [],
                       transitionType: "link",
                       url: getURL('openTab/b.html') }},
          { label: "b-onDOMContentLoaded",
            event: "onDOMContentLoaded",
            details: { frameId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       url: getURL('openTab/b.html') }},
          { label: "b-onCompleted",
            event: "onCompleted",
            details: { frameId: 0,
                       tabId: 1,
                       timeStamp: 0,
                       url: getURL('openTab/b.html') }}],
          [ navigationOrder("a-"),
            navigationOrder("b-"),
            navigationOrder("c-"),
            isIFrameOf("a-", "c-"),
            ["a-onDOMContentLoaded", "a-onCreatedNavigationTarget",
             "b-onBeforeNavigate"]]);
        chrome.tabs.update(tabId, { url: getURL('openTab/c.html') });
      },
    ]);
  });
}
