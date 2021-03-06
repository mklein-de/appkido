/*
 * AKFindPanelController.h
 *
 * Uses modifications to TextEdit example code owned and copyrighted by
 * Apple Computer.
 *
 * Created by Andy Lee on Thu May 15 2003.
 * Copyright (c) 2003, 2004 Andy Lee. All rights reserved.
 */

#import <Cocoa/Cocoa.h>

/*!
 * @class       AKFindPanelController
 * @discussion  Controller for the application-wide Find panel.
 */
@interface AKFindPanelController : NSObject
{
    // Did we find anything the last time we tried?  Used to decide what
    // to display in _statusTextField.
    BOOL _lastFindWasSuccessful;

    // UI outlets.
    IBOutlet NSTextField *_findTextField;
    IBOutlet NSButton *_findNextButton;
    IBOutlet NSTextField *_statusTextField;
}


#pragma mark -
#pragma mark Factory methods

/*!
 * @method      sharedInstance
 * @discussion  Returns the one and only instance of this class.
 */
+ (AKFindPanelController *)sharedInstance;


#pragma mark -
#pragma mark Action methods

- (IBAction)findNext:(id)sender;

- (IBAction)findPrevious:(id)sender;

- (IBAction)findNextAndOrderFindPanelOut:(id)sender;

- (IBAction)orderFrontFindPanel:(id)sender;

- (IBAction)takeFindStringFromSelection:(id)sender;

@end
