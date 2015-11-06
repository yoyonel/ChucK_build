/*----------------------------------------------------------------------------
 miniAudicle
 Cocoa GUI to chuck audio programming environment
 
 Copyright (c) 2005-2013 Spencer Salazar.  All rights reserved.
 http://chuck.cs.princeton.edu/
 http://soundlab.cs.princeton.edu/
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
 U.S.A.
 -----------------------------------------------------------------------------*/

/* Based in part on: */
//
//  DocumentViewController.h
//  MultiDocTest
//
//  Created by Cartwright Samuel on 3/14/13.
//  Copyright (c) 2013 Samuel Cartwright. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "chuck_def.h"

class miniAudicle;
@class NumberedTextView;
@class miniAudicleDocument;
@class mAMultiDocWindowController;

@interface mADocumentViewController : NSViewController {
@private
    miniAudicleDocument * _document;
    mAMultiDocWindowController * _windowController;
    
    IBOutlet NumberedTextView * text_view;
    IBOutlet NSTextField * status_text;
    IBOutlet NSTextField * argument_text;
    IBOutlet NSView * argument_view;
    
    NSMutableArray * arguments;
    
    miniAudicle * ma;
    t_CKUINT docid;
    
    BOOL _edited;
    BOOL _showsArguments;
    NSRect _argumentsViewFrame;
    BOOL _showsLineNumbers;
    BOOL _showsStatusBar;
    NSRect _statusBarViewFrame;
}

@property (assign, nonatomic) miniAudicleDocument* document;
@property (assign, nonatomic) mAMultiDocWindowController* windowController;
@property (nonatomic) BOOL isEdited;

- (void)activate;
- (IBAction)handleArgumentText:(id)sender;
- (BOOL)isEmpty;
- (NSString *)content;
- (void)setContent:(NSString *)_content;

- (void)setMiniAudicle:(miniAudicle *)_ma;

- (void)add:(id)sender;
- (void)remove:(id)sender;
- (void)replace:(id)sender;
- (void)removeall:(id)sender;
- (void)removelast:(id)sender;
- (void)clearVM:(id)sender;

- (void)setShowsArguments:(BOOL)_showsArguments;
- (BOOL)showsArguments;
- (void)setShowsLineNumbers:(BOOL)_showsLineNumbers;
- (BOOL)showsLineNumbers;
- (void)setShowsStatusBar:(BOOL)_showsStatusBar;
- (BOOL)showsStatusBar;

@end
