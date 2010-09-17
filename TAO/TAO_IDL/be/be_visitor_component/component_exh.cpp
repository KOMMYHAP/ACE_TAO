
//=============================================================================
/**
 *  @file    component_exh.cpp
 *
 *  $Id$
 *
 *  Visitor generating code for Components in the exec impl header.
 *
 *
 *  @author Jeff Parsons
 */
//=============================================================================

be_visitor_component_exh::be_visitor_component_exh (
      be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
  // This is initialized in the base class to svnt_export_macro()
  // or skel_export_macro(), since there are many more visitor
  // classes generating servant code. So we can just override
  // all that here.
  export_macro_ = be_global->exec_export_macro ();
}

be_visitor_component_exh::~be_visitor_component_exh (void)
{
}

int
be_visitor_component_exh::visit_component (be_component *node)
{
  this->node_ = node;

  /// CIDL-generated namespace used 'CIDL_' + composition name.
  /// Now we use 'CIAO_' + component's flat name.
  os_ << be_nl << be_nl
      << "namespace CIAO_" << node->flat_name ()
      << "_Impl" << be_nl
      << "{" << be_idt;
     
  be_visitor_facet_exh facet_visitor (this->ctx_);
  facet_visitor.node (node);
  
  if (facet_visitor.visit_component_scope (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_component_exh::")
                         ACE_TEXT ("visit_component - ")
                         ACE_TEXT ("facet visitor failed\n")),
                        -1);
    }
    
  be_visitor_executor_exh exec_visitor (this->ctx_);
    
  if (exec_visitor.visit_component (node) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_component_exh::")
                         ACE_TEXT ("visit_component - ")
                         ACE_TEXT ("exec visitor failed\n")),
                        -1);
    }
    
  this->gen_exec_entrypoint_decl ();

  os_ << be_uidt_nl
      << "}";
     
  return 0;
}
