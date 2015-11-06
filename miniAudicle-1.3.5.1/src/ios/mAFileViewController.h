/*----------------------------------------------------------------------------
 miniAudicle iOS
 iOS GUI to chuck audio programming environment
 
 Copyright (c) 2005-2012 Spencer Salazar.  All rights reserved.
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

#import <UIKit/UIKit.h>

@class mADetailViewController;
@class mAEditorViewController;
@class mAPlayerViewController;

@interface mAFileViewController : UIViewController
{
    IBOutlet UITableView * _tableView;
    IBOutlet UIBarButtonItem * _editButton;
    
    NSMutableArray * _scripts;
    int untitledNumber;
}

@property (strong, nonatomic) mAEditorViewController *editorViewController;
@property (strong, nonatomic) mAPlayerViewController *playerViewController;
@property (strong, nonatomic) mADetailViewController *detailViewController;
@property (strong, nonatomic) NSMutableArray * scripts;

@property (nonatomic) BOOL editable;

- (IBAction)newScript;
- (IBAction)editScripts;
- (IBAction)playMode:(id)sender;
- (IBAction)editMode:(id)sender;

- (void)selectScript:(int)script;
- (int)selectedScript;
- (void)scriptDetailChanged;
- (void)scriptsChanged;

@end
