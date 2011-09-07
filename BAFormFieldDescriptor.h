/*
 Copyright 2011 Dmitry Stadnik. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are
 permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this list of
 conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice, this list
 of conditions and the following disclaimer in the documentation and/or other materials
 provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY DMITRY STADNIK ``AS IS'' AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND
 FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL DMITRY STADNIK OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those of the
 authors and should not be interpreted as representing official policies, either expressed
 or implied, of Dmitry Stadnik.
*/

#import <UIKit/UIKit.h>

typedef enum {
	BAFormFieldTypeLabel,
	BAFormFieldTypeText,
	BAFormFieldTypeButton
} BAFormFieldType;

@class BAFormFieldDescriptor;

// Returns nil if value is OK and error message otherwise.
typedef NSString *(^BAFormFieldValidator)(id fieldValue, BAFormFieldDescriptor *fieldDescriptor, NSDictionary *formModel);

@interface BAFormFieldDescriptor : NSObject <UITextInputTraits> {
@private
	NSString *_identifier;
	NSString *_name;
	BAFormFieldType _type;                                // default is BAFormFieldTypeText
	NSString *_placeholder;
	UITextAlignment _textAlignment;
	UITextAutocapitalizationType _autocapitalizationType; // default is UITextAutocapitalizationTypeSentences
	UITextAutocorrectionType _autocorrectionType;         // default is UITextAutocorrectionTypeDefault
	UIKeyboardType _keyboardType;                         // default is UIKeyboardTypeDefault
	UIKeyboardAppearance _keyboardAppearance;             // default is UIKeyboardAppearanceDefault
	UIReturnKeyType _returnKeyType;                       // default is UIReturnKeyDefault (See note under UIReturnKeyType enum)
	BOOL _enablesReturnKeyAutomatically;                  // default is NO
	BOOL _secureTextEntry;                                // default is NO
	BAFormFieldValidator _validator;
}

@property(nonatomic, copy) NSString *identifier;
@property(nonatomic, copy) NSString *name;
@property(nonatomic, assign) BAFormFieldType type;
@property(nonatomic, copy) NSString *placeholder;
@property(nonatomic, assign) UITextAlignment textAlignment;
@property(nonatomic, retain) BAFormFieldValidator validator;

- (void)useRegexpValidator:(NSString *)regexp withErrorMessage:(NSString *)error;

@end
