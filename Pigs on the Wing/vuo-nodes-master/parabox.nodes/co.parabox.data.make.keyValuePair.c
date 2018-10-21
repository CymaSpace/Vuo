/**
 * @file
 * co.parabox.data.make.keyValuePair node implementation.
 *
 */


#include "node.h"

VuoModuleMetadata({
					 "title" : "Make Key Value Pair",
					 "keywords" : [ "kvp", "union", "tuple" ],
					 "version" : "1.0.0",
					 "description": "",
					 "node" : {
						  "exampleCompositions" : [ "" ]
					 }
				 });

void nodeEvent
(
	VuoInputData(VuoText, {"default":"name"}) key,
	VuoInputData(VuoGenericType1) value,
	VuoOutputData(VuoText) outKey,
	VuoOutputData(VuoGenericType1) outValue
)
{
// @todo make an actual kvp type
	*outKey = key;
	*outValue = value;
}
