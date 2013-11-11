/*
 Copyright (C) 2013 by Ivan Safrin
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 */
 
#include "EntityEditorPropertyView.h"


EntityEditorPropertyView::EntityEditorPropertyView() : UIElement() {
    entityProps = new PropList();
    addChild(entityProps);
    
    transformSheet = new TransformSheet();
    entityProps->addPropSheet(transformSheet);
    transformSheet->addEventListener(this, PropEvent::EVENT_PROP_CHANGE);
    
    materialSheet = new MaterialPropSheet();
    entityProps->addPropSheet(materialSheet);
    materialSheet->addEventListener(this, PropEvent::EVENT_PROP_CHANGE);
    
    primitiveSheet = new ScenePrimitiveSheet();
    entityProps->addPropSheet(primitiveSheet);
    primitiveSheet->addEventListener(this, PropEvent::EVENT_PROP_CHANGE);
    
    entitySheet = new EntitySheet();
    entityProps->addPropSheet(entitySheet);
    entitySheet->addEventListener(this, PropEvent::EVENT_PROP_CHANGE);
    
}

void EntityEditorPropertyView::Resize(Number width, Number height) {
    entityProps->Resize(width, height);
    UIElement::Resize(width, height);
}

void EntityEditorPropertyView::setEntity(Entity *entity) {
    
    SceneMesh *sceneMesh = dynamic_cast<SceneMesh*>(entity);
    materialSheet->setSceneMesh(sceneMesh);

    ScenePrimitive *scenePrimitive = dynamic_cast<ScenePrimitive*>(entity);
    primitiveSheet->setScenePrimitive(scenePrimitive);

    entitySheet->setEntity(entity);
    transformSheet->setEntity(entity);
    Resize(getWidth(), getHeight());
}

EntityEditorPropertyView::~EntityEditorPropertyView() {
}
