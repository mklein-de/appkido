/*
 * AKSavedWindowState.m
 *
 * Created by Andy Lee on Sun Jun 15 2003.
 * Copyright (c) 2003, 2004 Andy Lee. All rights reserved.
 */

#import "AKSavedWindowState.h"

#import "AKPrefUtils.h"
#import "AKDatabase.h"
#import "AKWindowLayout.h"
#import "AKDocLocator.h"

@implementation AKSavedWindowState

//-------------------------------------------------------------------------
// Preferences
//-------------------------------------------------------------------------

+ (AKSavedWindowState *)fromPrefDictionary:(NSDictionary *)prefDict
{
    if (prefDict == nil)
    {
        return nil;
    }

    AKSavedWindowState *windowState = [[[self alloc] init] autorelease];

    // Get the platform name.
    NSString *platformName = [prefDict objectForKey:AKPlatformNamePrefKey];

    if (platformName == nil)
    {
        platformName = AKMacOSPlatform;
    }

    [windowState setPlatformName:platformName];

    // Get the window layout.
    NSDictionary *windowLayoutPrefDict =
        [prefDict objectForKey:AKWindowLayoutPrefKey];
    AKWindowLayout *windowLayout =
        [AKWindowLayout fromPrefDictionary:windowLayoutPrefDict];

    [windowState setSavedWindowLayout:windowLayout];

    // Get the window's selected history item.
    NSDictionary *historyItemPrefDict =
        [prefDict objectForKey:AKSelectedDocPrefKey];
    AKDocLocator *historyItem =
        [AKDocLocator fromPrefDictionary:historyItemPrefDict];

    [windowState setSavedDocLocator:historyItem];

    return windowState;
}

- (NSDictionary *)asPrefDictionary
{
    NSMutableDictionary *prefDict = [NSMutableDictionary dictionary];

    if (_platformName)
    {
        [prefDict
            setObject:_platformName
            forKey:AKPlatformNamePrefKey];
    }

    [prefDict
        setObject:[_savedWindowLayout asPrefDictionary]
        forKey:AKWindowLayoutPrefKey];
    [prefDict
        setObject:[_savedDocLocator asPrefDictionary]
        forKey:AKSelectedDocPrefKey];

    return prefDict;
}

//-------------------------------------------------------------------------
// Getters and setters
//-------------------------------------------------------------------------

- (NSString *)platformName
{
    return _platformName;
}

- (void)setPlatformName:(NSString *)platformName
{
    [platformName retain];
    [_platformName release];
    _platformName = platformName;
}

- (AKWindowLayout *)savedWindowLayout
{
    return _savedWindowLayout;
}

- (void)setSavedWindowLayout:(AKWindowLayout *)windowLayout
{
    [windowLayout retain];
    [_savedWindowLayout release];
    _savedWindowLayout = windowLayout;
}

- (AKDocLocator *)savedDocLocator
{
    return _savedDocLocator;
}

- (void)setSavedDocLocator:(AKDocLocator *)docLocator
{
    [docLocator retain];
    [_savedDocLocator release];
    _savedDocLocator = docLocator;
}

@end
