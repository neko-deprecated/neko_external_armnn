//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "LayerWithParameters.hpp"

namespace armnn
{

/// This layer represents a SpaceToBatchNd operation.
class SpaceToBatchNdLayer : public LayerWithParameters<SpaceToBatchNdDescriptor>
{
public:
    /// Makes a workload for the SpaceToBatchNd type.
    /// @param [in] graph The graph where this layer can be found.
    /// @param [in] factory The workload factory which will create the workload.
    /// @return A pointer to the created workload, or nullptr if not created.
    virtual std::unique_ptr<IWorkload> CreateWorkload(const IWorkloadFactory& factory) const override;

    /// Creates a dynamically-allocated copy of this layer.
    /// @param [in] graph The graph into which this layer is being cloned.
    SpaceToBatchNdLayer* Clone(Graph& graph) const override;

    /// By default returns inputShapes if the number of inputs are equal to number of outputs,
    /// otherwise infers the output shapes from given input shapes and layer properties.
    /// @param [in] inputShapes The input shapes layer has.
    /// @return A vector to the inferred output shape.
    std::vector<TensorShape> InferOutputShapes(const std::vector<TensorShape>& inputShapes) const override;

    /// Check if the input tensor shape(s)
    /// will lead to a valid configuration of @ref SpaceToBatchNdLayer.
    void ValidateTensorShapesFromInputs() override;

    void Accept(ILayerVisitor& visitor) const override;

protected:
    /// Constructor to create a SpaceToBatchNdLayer.
    /// @param [in] param SpaceToBatchNdDescriptor to configure the SpaceToBatchNdLayer operation.
    /// @param [in] name Optional name for the layer.
    SpaceToBatchNdLayer(const SpaceToBatchNdDescriptor param, const char* name);

    /// Default destructor
    ~SpaceToBatchNdLayer() = default;
};

} // namespace
