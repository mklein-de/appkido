/*
 * AKPrefPanelController.h
 *
 * Created by Andy Lee on Sat Sep 07 2002.
 * Copyright (c) 2003, 2004 Andy Lee. All rights reserved.
 */

#import <Cocoa/Cocoa.h>

@class AKDevToolsPathController;

/*!
 * @class       AKPrefPanelController
 * @abstract    Controller for the application-wide Preferences panel.
 * @discussion  A single instance of AKPrefPanelController is managed by the
 *   app-wide singleton instance of AKAppController.
 */
@interface AKPrefPanelController : NSObject
{
    // IB outlets.
    IBOutlet NSTabView *_prefsTabView;

    // Controls in the Appearance tab.
    IBOutlet NSPopUpButton *_listFontNameChoice;
    IBOutlet NSComboBox *_listFontSizeCombo;

    IBOutlet NSPopUpButton *_headerFontNameChoice;
    IBOutlet NSComboBox *_headerFontSizeCombo;

    IBOutlet NSPopUpButton *_magnificationChoice;

    // Controls in the Frameworks tab.
    IBOutlet NSTableView *_frameworksTable;

    // Controls in the Dev Tools tab.
    // In our nib file, _devToolsPathController's two outlets are connected
    // to _devToolsPathField and _sdkVersionsPopUpButton.
    IBOutlet AKDevToolsPathController *_devToolsPathController;
    IBOutlet NSTextField *_devToolsPathField;
    IBOutlet NSPopUpButton *_sdkVersionsPopUpButton;
}


#pragma mark -
#pragma mark Factory methods

/*!
 * @method      sharedInstance
 * @discussion  Returns the one and only instance of this class.
 */
+ (AKPrefPanelController *)sharedInstance;


#pragma mark -
#pragma mark Action methods

- (IBAction)openPrefsPanel:(id)sender;

- (IBAction)applyAppearancePrefs:(id)sender;

- (IBAction)useDefaultAppearancePrefs:(id)sender;

- (IBAction)doFrameworksListAction:(id)sender;

- (IBAction)selectAllFrameworks:(id)sender;

- (IBAction)deselectAllFrameworks:(id)sender;

@end
