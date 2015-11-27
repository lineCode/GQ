/*
* This is a heavily modified fork of gumbo-query by Hoping White aka LazyTiger.
* The original software can be found at: https://github.com/lazytiger/gumbo-query
*
* gumbo-query is based on cascadia, written by Andy Balholm.
*
* Copyright (c) 2011 Andy Balholm. All rights reserved.
* Copyright (c) 2015 Hoping White aka LazyTiger (hoping@baimashi.com)
* Copyright (c) 2015 Jesse Nicholson
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/

#pragma once

#include <gumbo.h>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

namespace gumboquery
{	
	
	class GQNode;

	/// <summary>
	/// GQUtil is, as the name suggested, a Utility class containing behavior that is commonly
	/// beneficial across all classes.
	/// </summary>
	class GQUtil
	{

	public:		

		/// <summary>
		/// Get the text of the supplied node and all of its descendants. 
		/// </summary>
		/// <param name="node">
		/// The node from which to extract text from it and all of its descendants. 
		/// </param>
		/// <returns>
		/// All text contained in the supplied node and all of its descendants combined. 
		/// </returns>
		static std::string NodeText(const GumboNode* node);

		/// <summary>
		/// Get the text of only the children of the supplied node.
		/// </summary>
		/// <param name="node">
		/// The node from which to extract the text contents of its children.
		/// </param>
		/// <returns>
		/// All text contained in the direct children of the supplied node combined.
		/// </returns>
		static std::string NodeOwnText(const GumboNode* node);

		/// <summary>
		/// Checks if the supplied node to search for already exists inside the supplied collection
		/// of nodes.
		/// </summary>
		/// <param name="nodeCollection">
		/// The collection of nodes to search within. 
		/// </param>
		/// <param name="search">
		/// The node to search for. 
		/// </param>
		/// <returns>
		/// True if the supplied search node was found in the supplied collection of nodes, false
		/// otherwise.
		/// </returns>
		static bool NodeExists(const std::vector< std::shared_ptr<GQNode> >& nodeCollection, const GumboNode* search);

		/// <summary>
		/// Takes the supplied primary collection and adds any nodes to it contained in the second
		/// collection which it does not already contain. This is for merging new match results into
		/// existing match results without creating duplicate matches.
		/// 
		/// Null checks are not performed. It is the responsibility of the user to ensure that the
		/// supplied collections are populated with valid pointers.
		/// </summary>
		/// <param name="primaryCollection">
		/// The primary collection containing unique nodes discovered during matching. This
		/// collection will have any nodes it does not already contain, which are found in the
		/// second collection, added to it.
		/// </param>
		/// <param name="collection">
		/// A collection of nodes to add to the primary collection only if they do not already exist
		/// in the primary collection.
		/// </param>
		/// <returns>
		/// </returns>
		static void UnionNodes(std::vector< std::shared_ptr<GQNode> >& primaryCollection, const std::vector< std::shared_ptr<GQNode> >& collection);

	private:

		/// <summary>
		/// 
		/// </summary>
		/// <param name="node"></param>
		/// <param name="stringContainer"></param>
		static void WriteNodeText(const GumboNode* node, std::string& stringContainer);

		GQUtil();
		~GQUtil();

	};

} /* namespace gumboquery */