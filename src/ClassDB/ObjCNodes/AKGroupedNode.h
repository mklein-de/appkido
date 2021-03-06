//
//  AKGroupedNode.h
//  AppKiDo
//
//  Created by Andy Lee on 4/25/08.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import "AKDatabaseNode.h"

@interface AKGroupedNode : AKDatabaseNode
{
@private
    NSString *_groupName;
}


#pragma mark -
#pragma mark Init/awake/dealloc


#pragma mark -
#pragma mark Init/awake/dealloc

// Designated initializer.
- (id)initWithNodeName:(NSString *)nodeName
    owningFramework:(AKFramework *)theFramework
    groupName:(NSString *)groupName;


#pragma mark -
#pragma mark Getters and setters

- (NSString *)groupName;

@end
